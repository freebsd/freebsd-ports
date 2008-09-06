--- plugins/org.eclipse.update.core.freebsd/src/update.c.orig	2007-09-01 18:09:27.000000000 +0900
+++ plugins/org.eclipse.update.core.freebsd/src/update.c	2007-09-01 18:24:02.000000000 +0900
@@ -12,7 +12,8 @@
 /* bug 82520 : need to include stdlib.h */
 # include <stdlib.h>
 # include <sys/types.h>
-# include <sys/statfs.h>
+# include <sys/param.h>
+# include <sys/mount.h>
 # include <update.h>
 
 /*
