--- togl/togl.cpp.orig	Wed Sep 29 19:48:06 2004
+++ togl/togl.cpp	Wed Nov 17 22:15:57 2004
@@ -140,6 +140,8 @@
 #  include "tkInt8.4p4.h"
 #elif TK_MAJOR_VERSION==8 && TK_MINOR_VERSION==4 && TK_RELEASE_SERIAL==6
 #  include "tkInt8.4p6.h"
+#elif TK_MAJOR_VERSION==8 && TK_MINOR_VERSION==4 && TK_RELEASE_SERIAL==7
+#  include "tkInt8.4p6.h"
 #else
    Sorry, you will have to edit togl.c to include the right tkInt.h file
 #endif
