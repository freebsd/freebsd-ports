--- src/argyll/spectro/usbio.c.orig	2009-03-07 21:18:13.000000000 +0300
+++ src/argyll/spectro/usbio.c	2009-03-07 21:18:41.000000000 +0300
@@ -20,6 +20,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <time.h>
 #include <signal.h>
 #if defined(UNIX)
