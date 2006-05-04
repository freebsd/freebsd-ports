--- src/celutil/util.h.orig	Thu May  4 11:51:00 2006
+++ src/celutil/util.h	Thu May  4 11:51:12 2006
@@ -28,6 +28,7 @@
 #ifdef _WIN32
 #define _(s) s
 #else
+#include <libintl.h>
 #define _(s) gettext(s)
 #endif
 
