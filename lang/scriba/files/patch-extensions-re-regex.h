--- extensions/re/regex.h.orig	Tue Mar  1 22:12:11 2005
+++ extensions/re/regex.h	Tue Mar  1 22:14:55 2005
@@ -53,6 +53,8 @@
 #define __stdcall
 #endif
 
+#include <unistd.h>
+
 /* types */
 typedef off_t regoff_t;
 
