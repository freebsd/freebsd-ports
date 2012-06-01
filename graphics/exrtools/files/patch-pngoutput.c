--- src/pngoutput.c.orig	2003-12-08 18:33:27.000000000 +0100
+++ src/pngoutput.c	2012-04-25 06:41:11.000000000 +0200
@@ -27,6 +27,7 @@
 #include <errno.h>
 #include <string.h>
 #include <png.h>
+#include <zlib.h>
 #include "pngoutput.h"
 
 struct pngoutput_s
