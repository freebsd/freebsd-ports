--- lib/ghIntegration/ghIntegrationX11.c.orig	2009-02-18 17:02:42.000000000 +0900
+++ lib/ghIntegration/ghIntegrationX11.c	2009-03-24 19:18:47.000000000 +0900
@@ -62,7 +62,9 @@
 #include "imageUtil.h"
 #include "strutil.h"
 #include <paths.h>
+#if defined(linux)
 #include <mntent.h>
+#endif
 #include "vm_atomic.h"
 #include "ghIntegration.h"
 #include "ghIntegrationInt.h"
