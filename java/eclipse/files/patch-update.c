--- plugins/org.eclipse.update.core.linux/src/update.c.orig	Sun Jun 13 22:47:30 2004
+++ plugins/org.eclipse.update.core.linux/src/update.c	Sun Jun 13 22:48:22 2004
@@ -10,8 +10,14 @@
  *******************************************************************************/
 
 # include <sys/types.h>
+#ifdef __FreeBSD__
+# include <sys/param.h>
+# include <sys/mount.h>
+# include "update.h"
+#else
 # include <sys/statfs.h>
 # include <update.h>
+#endif
 
 /*
  * Class:     org_eclipse_update_configuration_LocalSystemInfo
