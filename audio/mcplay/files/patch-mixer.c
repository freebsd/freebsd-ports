--- mixer.c.orig	2010-03-18 18:58:51.000000000 -0700
+++ mixer.c	2010-03-18 18:59:10.000000000 -0700
@@ -7,7 +7,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <errno.h>
 #include <string.h>
 
