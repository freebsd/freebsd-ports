--- src/xcf2png.c.orig	2013-02-12 19:30:10.000000000 +0100
+++ src/xcf2png.c	2014-09-11 01:38:20.000000000 +0200
@@ -23,6 +23,13 @@
 #include "palette.h"
 
 #include <png.h>
+#ifndef png_voidp_NULL
+#define png_voidp_NULL (png_voidp)NULL
+#endif
+#ifndef png_error_ptr_NULL
+#define png_error_ptr_NULL (png_error_ptr)NULL
+#endif
+
 #include <stdlib.h>
 #include <string.h>
 #include <locale.h>
