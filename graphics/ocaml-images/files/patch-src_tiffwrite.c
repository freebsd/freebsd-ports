--- src/tiffwrite.c.orig	2011-06-22 20:04:32.000000000 +0200
+++ src/tiffwrite.c
@@ -20,11 +20,16 @@
 #include <caml/memory.h>
 #include <caml/fail.h>
 
+/* Avoid redefinitions */
+#undef int16
+#undef uint16
 /* These are defined in caml/config.h */
 #define int16 int16tiff
 #define uint16 uint16tiff
 #define int32 int32tiff
 #define uint32 uint32tiff
+#define int64 int64tiff
+#define uint64 uint64tiff
 
 #include <tiffio.h>
 
@@ -32,6 +37,8 @@
 #undef uint16
 #undef int32
 #undef uint32
+#undef int64
+#undef uint64
 
 extern value *imglib_error;
 
