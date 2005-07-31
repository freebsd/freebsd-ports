--- plugins/org.eclipse.update.core.linux/src/update.c.orig	Fri May 13 11:37:58 2005
+++ plugins/org.eclipse.update.core.linux/src/update.c	Sat May 14 19:01:31 2005
@@ -12,7 +12,12 @@
 /* bug 82520 : need to include stdlib.h */
 # include <stdlib.h>
 # include <sys/types.h>
+#ifdef __FreeBSD__
+# include <sys/param.h>
+# include <sys/mount.h>
+#else
 # include <sys/statfs.h>
+#endif
 # include <update.h>
 
 /*
