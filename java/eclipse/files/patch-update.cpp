--- plugins/org.eclipse.update.core.linux/src/update.cpp.orig	Tue Mar  4 14:18:02 2003
+++ plugins/org.eclipse.update.core.linux/src/update.cpp	Tue Mar  4 14:20:21 2003
@@ -3,8 +3,8 @@
  * All Rights Reserved.
  */
 
-# include <sys/types.h>
-# include <sys/statfs.h>
+# include <sys/param.h>
+# include <sys/mount.h>
 # include <update.h>
 
 /*
