--- plugins/output-pngfile/output-pngfile.c.orig	2011-03-26 02:52:29.000000000 +0100
+++ plugins/output-pngfile/output-pngfile.c	2012-05-12 14:23:21.000000000 +0200
@@ -23,6 +23,7 @@
 #include <gettext.h>
 #include "config.h"
 #include <png.h>
+#include <zlib.h>
 
 #define RS_TYPE_PNGFILE (rs_pngfile_type)
 #define RS_PNGFILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RS_TYPE_PNGFILE, RSPngfile))
