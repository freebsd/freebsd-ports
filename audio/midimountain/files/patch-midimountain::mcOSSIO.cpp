--- midimountain/mcOSSIO.cpp.orig	Sat Dec 15 14:03:49 2001
+++ midimountain/mcOSSIO.cpp	Sat Dec 15 14:03:56 2001
@@ -1,7 +1,7 @@
 //=============================================================================
 // implementation class midi IO
 //=============================================================================
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
