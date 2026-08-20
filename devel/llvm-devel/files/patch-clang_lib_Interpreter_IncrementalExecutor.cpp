--- clang/lib/Interpreter/IncrementalExecutor.cpp.orig
+++ clang/lib/Interpreter/IncrementalExecutor.cpp
@@ -76,7 +76,7 @@
 // and AIX / z/OS (whose runtimes may not provide the symbol). On those hosts
 // thread_locals instead rely on process-symbol lookup, unchanged from before.
 #if defined(LLVM_ON_UNIX) && !defined(__EMSCRIPTEN__) && !defined(_AIX) &&     \
-    !defined(__MVS__)
+    !defined(__MVS__) && !defined(__FreeBSD__)
 extern "C" void *__emutls_get_address(void *);
 static void *getEmuTLSGetAddressPtr() {
   return reinterpret_cast<void *>(&__emutls_get_address);
