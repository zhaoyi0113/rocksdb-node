#include <nan.h>
#include <node.h>
#include "DBNode.h"
#include "Iterator.h"
#include "Snapshot.h"
#include "Batch.h"
#include "FileWriter.h"

void InitAll(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
  DBNode::Init();
  Iterator::Init();
  Snapshot::Init();
  Batch::Init();
  FileWriter::Init();
  NODE_SET_METHOD(exports, "open", DBNode::NewInstance);
  Nan::SetMethod(exports, "listColumnFamilies", DBNode::ListColumnFamilies);
  Nan::SetMethod(exports, "destroyDB", DBNode::DestroyDB);
}

NODE_MODULE(addon, InitAll)
