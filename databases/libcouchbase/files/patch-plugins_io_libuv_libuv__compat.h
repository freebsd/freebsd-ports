--- plugins/io/libuv/libuv_compat.h.orig	2023-06-03 18:58:46 UTC
+++ plugins/io/libuv/libuv_compat.h
@@ -35,6 +35,10 @@
 #define UNKNOWN -1
 #endif
 
+#ifndef ENODATA
+#define ENODATA EPIPE
+#endif
+
 #ifndef EAIFAMNOSUPPORT
 #define EAIFAMNOSUPPORT EAI_FAMILY
 #endif
