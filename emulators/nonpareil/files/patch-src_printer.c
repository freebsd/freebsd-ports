--- src/printer.c.orig	2012-05-09 13:00:47.000000000 +0200
+++ src/printer.c	2012-05-09 13:01:08.000000000 +0200
@@ -29,6 +29,7 @@
 #include <gtk/gtk.h>
 
 #include <png.h>
+#include <zlib.h>
 
 #include "util.h"
 #include "display.h"
