--- myodbcinst/myodbcinst.c.orig	Mon Oct 10 05:49:47 2005
+++ myodbcinst/myodbcinst.c	Thu Oct 27 16:33:29 2005
@@ -56,7 +56,11 @@
     #include <ltdl.h>
 #endif
 
+# if defined(HAVE_IODBCINST_H)
+#include <iodbcinst.h>
+#elif defined(HAVE_ODBCINST_H)
 #include <odbcinst.h>
+# endif
 
 #include "../util/MYODBCUtil.h"
 
