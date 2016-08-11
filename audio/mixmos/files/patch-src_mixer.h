--- src/mixer.h.orig	2003-12-14 18:23:19 UTC
+++ src/mixer.h
@@ -23,7 +23,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
 #include <stdio.h>
