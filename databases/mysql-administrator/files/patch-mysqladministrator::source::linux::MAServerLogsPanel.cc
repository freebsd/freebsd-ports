--- mysqladministrator/source/linux/MAServerLogsPanel.cc.orig	Wed Feb 11 22:38:41 2004
+++ mysqladministrator/source/linux/MAServerLogsPanel.cc	Tue Feb 24 03:56:22 2004
@@ -21,7 +21,8 @@
 #include "MDataInterface.h"
 
 #include "myx_admin_public_interface.h"
-
+#include <errno.h>
+#include <math.h>
 
 #define PAGE_BLOCK_SIZE (1024*5)
 
@@ -144,7 +145,11 @@
 
 void MAServerLogsPanel::scroll_log(LogType type)
 {
+#if defined(__FreeBSD__)
+  double val= floor(_sbar[type]->get_value());
+#else
   double val= round(_sbar[type]->get_value());
+#endif
   _sbar[type]->set_value(val);
 
   process_logs(type);
