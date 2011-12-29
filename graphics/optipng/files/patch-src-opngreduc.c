--- src/opngreduc.c.orig	2011-12-29 14:47:34.000000000 +0100
+++ src/opngreduc.c	2011-12-29 14:48:52.000000000 +0100
@@ -27,6 +27,8 @@
 #if PNG_LIBPNG_VER >= 10400
 #ifdef PNG_USER_PRIVATEBUILD
 #include "pngpriv.h"
+#else
+#include "libpng/pngpriv.h"
 #endif
 #endif
 
