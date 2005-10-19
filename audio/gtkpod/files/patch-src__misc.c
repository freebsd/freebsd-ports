--- src/misc.c.orig	Tue Oct 18 22:37:32 2005
+++ src/misc.c	Tue Oct 18 22:37:48 2005
@@ -347,6 +347,7 @@
  * does not check prefs to see if the current prefs want gtkpod itself to
  * mount the ipod drive, that should be checked before making this call.
  */
+#include <sys/param.h>
 #include <sys/mount.h>
 #include <errno.h>
 #include <stdio.h>
