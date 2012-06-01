--- src/pngio.c.orig	2011-02-01 06:41:12.000000000 +0100
+++ src/pngio.c	2012-05-04 12:33:51.000000000 +0200
@@ -107,6 +107,7 @@
 /* --------------------------------------------*/
 
 #include "png.h"
+#include "zlib.h"
 
 /* ----------------Set defaults for read/write options ----------------- */
     /* strip 16 bpp --> 8 bpp on reading png; default is for stripping */
