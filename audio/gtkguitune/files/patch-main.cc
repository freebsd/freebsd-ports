--- main.cc.orig	Sat May 31 16:31:12 2003
+++ main.cc	Sat Feb 12 11:22:19 2005
@@ -24,7 +24,11 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 
 #include <gtk/gtk.h>
 #include <gtk--/window.h>
