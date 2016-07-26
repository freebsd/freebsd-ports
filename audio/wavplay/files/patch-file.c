--- file.c.orig	1999-12-04 00:06:42 UTC
+++ file.c
@@ -56,7 +56,9 @@ static const char rcsid[] = "@(#)file.c 
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
+#ifndef FREEBSD
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <memory.h>
 #include <signal.h>
@@ -64,7 +66,11 @@ static const char rcsid[] = "@(#)file.c 
 #include <sys/ipc.h>
 #include <sys/ioctl.h>
 #include <assert.h>
+#ifndef FREEBSD
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 #include "wavplay.h"
 
 extern int clntIPC;    /* Needed for message passing in PlayDSP */
