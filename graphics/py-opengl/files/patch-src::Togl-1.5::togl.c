--- src/Togl-1.5/togl.c.bak	Tue May 15 07:55:19 2001
+++ src/Togl-1.5/togl.c	Wed Aug 20 19:21:01 2003
@@ -137,6 +137,8 @@
 #  include "tkInt8.0p2.h"
 #elif TK_MAJOR_VERSION==8 && TK_MINOR_VERSION==3
 #  include "tkInt8.3.h"
+#elif TK_MAJOR_VERSION==8 && TK_MINOR_VERSION==4
+#  include "tkInt8.4.h"
 #else
 #error Sorry, you will have to edit togl.c to include the right tkInt.h file
 #endif
