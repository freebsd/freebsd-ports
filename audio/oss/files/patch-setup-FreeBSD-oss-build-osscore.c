--- setup/FreeBSD/oss/build/osscore.c.orig	Fri Jun 15 22:37:18 2007
+++ setup/FreeBSD/oss/build/osscore.c	Fri Jun 15 22:37:28 2007
@@ -7,7 +7,7 @@
  * In this way the same OSS binary package can be used with several FreeBSD
  * versions.
  */
-#include "/usr/include/stdarg.h"
+#include <stdarg.h>
 #include <sys/param.h>		/* defines used in kernel.h */
 #include <sys/module.h>
 #include <sys/systm.h>
