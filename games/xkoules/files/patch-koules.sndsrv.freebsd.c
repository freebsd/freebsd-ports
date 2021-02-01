--- koules.sndsrv.freebsd.c.orig	1998-03-04 18:59:19 UTC
+++ koules.sndsrv.freebsd.c
@@ -14,7 +14,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/time.h>
 #include <signal.h>
 #include <string.h>
