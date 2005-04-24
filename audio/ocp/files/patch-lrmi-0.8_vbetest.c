--- lrmi-0.8/vbetest.c.orig	Fri Mar 25 18:13:15 2005
+++ lrmi-0.8/vbetest.c	Sat Apr 23 19:51:05 2005
@@ -18,7 +18,8 @@
 #include <dev/wscons/wsconsio.h>
 #include <machine/sysarch.h>
 #elif defined(__FreeBSD__)
-#include <machine/console.h>
+#include <sys/consio.h>
+#include <sys/kbio.h>
 #include <machine/sysarch.h>
 #endif
 
