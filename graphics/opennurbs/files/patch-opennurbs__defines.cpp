--- opennurbs_defines.cpp.orig	2026-04-14 14:48:14 UTC
+++ opennurbs_defines.cpp
@@ -495,8 +495,8 @@ int ON::CloseAllFiles()
   // returns number of files closed or EOF for error
 #if defined(ON_COMPILER_MSC)
   return _fcloseall(); // ANSI C name
-#elif defined(ON_RUNTIME_APPLE) || defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_WASM)
-  //fcloseall is not supported on mac/ios or android
+#elif defined(ON_RUNTIME_APPLE) || defined(ON_RUNTIME_ANDROID) || defined(ON_RUNTIME_WASM) || defined(__FreeBSD__) 
+  //fcloseall is not supported on mac/ios or android or FreeBSD
   return EOF;
 #else
   return fcloseall();
