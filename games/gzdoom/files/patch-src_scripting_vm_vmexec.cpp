--- src/scripting/vm/vmexec.cpp.orig	2017-06-22 13:59:05 UTC
+++ src/scripting/vm/vmexec.cpp
@@ -229,7 +229,7 @@ void VMFillParams(VMValue *params, VMFrame *callee, in
 }
 
 
-#ifdef _DEBUG
+#ifndef NDEBUG
 bool AssertObject(void * ob)
 {
 	auto obj = (DObject*)ob;
