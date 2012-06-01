--- gif2png.h.orig	2010-10-20 00:11:28.000000000 +0200
+++ gif2png.h	2012-04-25 06:50:10.000000000 +0200
@@ -2,6 +2,8 @@
 
 /* get png type definitions */
 #include "png.h"
+#include "pngpriv.h"
+#include "zlib.h"
 
 #define GIFterminator ';'
 #define GIFextension '!'
