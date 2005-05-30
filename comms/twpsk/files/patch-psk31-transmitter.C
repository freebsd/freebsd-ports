--- modes/psk31-transmitter.C.orig	Fri Sep  1 21:01:34 2000
+++ modes/psk31-transmitter.C	Mon May 30 23:27:40 2005
@@ -11,7 +11,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/ioctl.h>
 #include "psk31-coder.h"
 #include "psk31-transmitter.h"
