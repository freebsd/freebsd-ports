--- src/printer.c.orig	2008-08-24 00:37:18 UTC
+++ src/printer.c
@@ -29,6 +29,7 @@ MA 02111, USA.
 #include <gtk/gtk.h>
 
 #include <png.h>
+#include <zlib.h>
 
 #include "util.h"
 #include "display.h"
