--- asmixer.c.orig	Sun Aug 31 15:23:26 2003
+++ asmixer.c	Sun Aug 31 15:24:45 2003
@@ -31,8 +31,8 @@
 #include <unistd.h>
 
 #ifdef __FreeBSD__
-#include <sys/syslimits.h>
 #include <sys/param.h>
+#include <sys/soundcard.h>
 #endif
 
 #include <sys/mount.h>
