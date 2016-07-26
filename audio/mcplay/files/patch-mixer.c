--- mixer.c.orig	2002-04-28 13:30:35 UTC
+++ mixer.c
@@ -7,7 +7,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <errno.h>
 #include <string.h>
 
