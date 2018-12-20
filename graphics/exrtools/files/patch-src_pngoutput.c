--- src/pngoutput.c.orig	2003-12-08 17:33:27 UTC
+++ src/pngoutput.c
@@ -27,6 +27,7 @@
 #include <errno.h>
 #include <string.h>
 #include <png.h>
+#include <zlib.h>
 #include "pngoutput.h"
 
 struct pngoutput_s
