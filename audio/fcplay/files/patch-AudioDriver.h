--- AudioDriver.h.orig	Mon Mar  3 21:47:00 1997
+++ AudioDriver.h	Sun May 18 11:12:48 2003
@@ -7,14 +7,15 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
+#include "Config.h"
 
 // These next includes were not required if libsidplay would not
 // provide related HAVE_* definitions.
 #include <sidplay/compconf.h>
 #if defined(HAVE_LINUX) && defined(HAVE_LINUX_SOUNDCARD_H)
   #include <linux/soundcard.h>
-#elif defined(HAVE_FREEBSD) && defined(HAVE_MACHINE_SOUNDCARD_H)
-  #include <machine/soundcard.h>
+#elif defined(HAVE_FREEBSD) && defined(HAVE_SYS_SOUNDCARD_H)
+  #include <sys/soundcard.h>
 #elif defined(HAVE_NETBSD) && defined(HAVE_SOUNDCARD_H)
   #include <soundcard.h>
 #else
