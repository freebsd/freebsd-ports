--- guitune.cc.orig	Sat Feb 12 11:14:56 2005
+++ guitune.cc	Sat Feb 12 11:15:02 2005
@@ -24,7 +24,11 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 
 #include <gtk--/main.h>
 #include <gtk--/box.h>
