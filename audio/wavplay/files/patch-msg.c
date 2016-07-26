--- msg.c.orig	1999-12-04 00:06:42 UTC
+++ msg.c
@@ -47,7 +47,9 @@ static const char rcsid[] = "@(#)msg.c $
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
+#ifndef FREEBSD
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <memory.h>
 #include <signal.h>
@@ -56,7 +58,11 @@ static const char rcsid[] = "@(#)msg.c $
 #include <sys/msg.h>
 #include <sys/ioctl.h>
 #include <assert.h>
+#ifndef FREEBSD
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 #include "wavplay.h"
 
 /*
