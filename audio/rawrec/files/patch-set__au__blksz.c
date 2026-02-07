--- set_au_blksz.c.orig	2006-01-05 17:36:27 UTC
+++ set_au_blksz.c
@@ -8,7 +8,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/ioctl.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 #include "rawrec.h" 
 
