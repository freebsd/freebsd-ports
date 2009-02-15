--- plugins/org.eclipse.update.core.freebsd/src/update.c.orig	2008-08-05 23:34:48.000000000 -0400
+++ plugins/org.eclipse.update.core.freebsd/src/update.c	2008-08-05 23:35:29.000000000 -0400
@@ -11,8 +11,9 @@
 
 /* bug 82520 : need to include stdlib.h */
 # include <stdlib.h>
+# include <sys/param.h>
 # include <sys/types.h>
-# include <sys/statfs.h>
+# include <sys/mount.h>
 # include <update.h>
 
 /*
