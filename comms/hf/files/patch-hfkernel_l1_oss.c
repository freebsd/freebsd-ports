--- hfkernel/l1/oss.c.orig	Sun Jul 30 10:58:19 2006
+++ hfkernel/l1/oss.c	Sun Jul 30 10:59:19 2006
@@ -30,7 +30,6 @@
 #include "config.h"
 #endif
 
-#include <asm/byteorder.h>
 #include <sys/soundcard.h>
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -44,7 +43,6 @@
 #include <sys/ioctl.h>
 #include <sys/time.h>
 #include <signal.h>
-#include <endian.h>
 #include <pthread.h>
 #include <syslog.h>
 
