--- ./koules.sndsrv.freebsd.c.orig	1998-03-04 19:59:19.000000000 +0100
+++ ./koules.sndsrv.freebsd.c	2014-03-30 03:11:00.579428909 +0200
@@ -14,7 +14,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/time.h>
 #include <signal.h>
 #include <string.h>
