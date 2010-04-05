--- src/opngreduc.c.orig	2010-01-03 06:59:00.000000000 +0100
+++ src/opngreduc.c	2010-04-05 22:02:26.000000000 +0200
@@ -23,7 +23,7 @@
 #define PNG_NO_PEDANTIC_WARNINGS
 #include "png.h"
 #if PNG_LIBPNG_VER >= 10400
-#include "pngpriv.h"
+#include "libpng/pngpriv.h"
 #else
 #define trans_alpha trans
 #define trans_color trans_values
