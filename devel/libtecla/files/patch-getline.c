--- getline.c.orig	Wed Feb 13 11:36:13 2002
+++ getline.c	Tue May  6 04:09:17 2003
@@ -45,6 +45,7 @@
  */
 #include <sys/ioctl.h>
 #ifdef HAVE_SELECT
+#include <sys/select.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #endif
