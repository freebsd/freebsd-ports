--- linux_x/i_sound.c.orig	Sat Jan 18 18:24:12 2003
+++ linux_x/i_sound.c	Sat Jan 18 18:23:42 2003
@@ -93,7 +93,7 @@
 // Linux voxware output.
 #ifdef LINUX
 #ifdef FREEBSD
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #else
 #include <linux/soundcard.h>
 #endif
