--- qgo/src/wavplay.c.orig	Tue Jun 24 06:57:09 2003
+++ qgo/src/wavplay.c	Mon Nov  3 00:50:02 2003
@@ -55,12 +55,11 @@
 #include <stdio.h>
 #include <stdarg.h>
 #include <stdlib.h>
-#include <malloc.h>
 #include <string.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/stat.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include "wavplay.h"
 //#include "server.h"
 
