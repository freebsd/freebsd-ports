--- plugins/org.eclipse.update.core.linux/src/update.c.orig	Thu Sep 16 08:48:27 2004
+++ plugins/org.eclipse.update.core.linux/src/update.c	Fri Feb 18 20:27:34 2005
@@ -10,8 +10,15 @@
  *******************************************************************************/
 
 # include <sys/types.h>
+#ifdef __FreeBSD__
+# include <stdlib.h>
+# include <sys/param.h>
+# include <sys/mount.h>
+# include "update.h"
+#else
 # include <sys/statfs.h>
 # include <update.h>
+#endif
 
 /*
  * Class:     org_eclipse_update_configuration_LocalSystemInfo
