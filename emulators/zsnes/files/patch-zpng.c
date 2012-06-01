--- zip/zpng.c.orig	2007-01-16 00:06:29.000000000 +0100
+++ zip/zpng.c	2012-05-06 16:01:13.000000000 +0200
@@ -21,6 +21,7 @@
 
 #ifndef NO_PNG
 #include <png.h>
+#include <pngpriv.h>
 #endif
 
 #ifdef __UNIXSDL__
