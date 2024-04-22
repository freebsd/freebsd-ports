--- test_dsp_params.c.orig	2006-01-05 17:36:27 UTC
+++ test_dsp_params.c
@@ -16,7 +16,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 #include "rawrec.h"
 
