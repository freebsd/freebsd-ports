--- wmslib/src/wms/snd.c.orig	Tue Jan 25 13:40:26 2000
+++ wmslib/src/wms/snd.c	Mon Nov 17 21:15:17 2003
@@ -14,7 +14,7 @@
 #if  !HAVE_GETDTABLESIZE
 #include <sys/resource.h>
 #endif
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/wait.h>
 #endif
 
