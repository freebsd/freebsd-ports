--- src/tiffwrite.c.orig	2009-10-26 13:42:03.000000000 +0100
+++ src/tiffwrite.c	2010-08-28 10:46:35.000000000 +0200
@@ -25,6 +25,8 @@
 #define uint16 uint16tiff
 #define int32 int32tiff
 #define uint32 uint32tiff
+#define int64 int64tiff
+#define uint64 uint64tiff
 
 #include <tiffio.h>
 
@@ -32,6 +34,8 @@
 #undef uint16
 #undef int32
 #undef uint32
+#undef int64
+#undef uint64
 
 extern value *imglib_error;
 
