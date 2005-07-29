--- vcl/unx/source/app/osssound.cxx.orig	Sun Jul 21 10:20:34 2002
+++ vcl/unx/source/app/osssound.cxx	Sun Jul 21 10:21:28 2002
@@ -72,7 +72,11 @@
 #include <unistd.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#ifdef LINUX
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 #include <errno.h>
 
 #ifdef _USE_NAMESPACE
