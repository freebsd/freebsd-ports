--- src/scripting/vm/vm.h.orig	2017-06-22 13:58:53 UTC
+++ src/scripting/vm/vm.h
@@ -376,7 +376,7 @@ int VMCall(VMFunction *func, VMValue *params, int nump
 // variable name <x> at position <p>
 void NullParam(const char *varname);
 
-#ifdef _DEBUG
+#ifndef NDEBUG
 bool AssertObject(void * ob);
 #endif
 
