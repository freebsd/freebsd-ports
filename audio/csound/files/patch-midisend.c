$FreeBSD$

--- midisend.c.orig	Sun Jul 14 16:03:01 2002
+++ midisend.c	Sun Jul 14 16:02:53 2002
@@ -16,7 +16,7 @@
 #include <ctype.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#ifdef FREE_BSD
+#ifdef __FreeBSD__
 #  include <sys/soundcard.h>
 #else
 #  include <linux/soundcard.h>
