--- src/alien.c.orig
+++ src/alien.c
@@ -332,7 +332,7 @@
 #define FFI_STDCALL FFI_DEFAULT_ABI
 #endif
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(BSD)
 #define FFI_SYSV FFI_DEFAULT_ABI
 #endif
 
