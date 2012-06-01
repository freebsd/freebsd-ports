--- src/tuxpaint.c.orig	2009-06-18 22:51:58.000000000 +0200
+++ src/tuxpaint.c	2012-05-09 12:18:19.000000000 +0200
@@ -410,6 +410,7 @@
 #endif
 
 #include <png.h>
+#include <pngpriv.h>
 #define FNAME_EXTENSION ".png"
 #ifndef PNG_H
 #error "---------------------------------------------------"
