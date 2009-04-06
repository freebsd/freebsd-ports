--- Togl/src/Togl/togl.c.orig	2006-03-22 18:39:27.000000000 -0600
+++ Togl/src/Togl/togl.c	2009-03-27 00:09:05.889967432 -0500
@@ -151,7 +151,7 @@
 #  include "tkInt8.2.h"
 #elif TK_MAJOR_VERSION==8 && TK_MINOR_VERSION==3
 #  include "tkInt8.3.h"
-#elif TK_MAJOR_VERSION==8 && TK_MINOR_VERSION==4
+#elif TK_MAJOR_VERSION==8 && TK_MINOR_VERSION>=4
 #  include "tkInt8.4.h"
 #else
    Sorry, you will have to edit togl.c to include the right tkInt.h file
