This revert wine-proton use of an ntsync.h header incompatible with any other OS than Linux

--- server/inproc_sync.c.orig	2026-08-03 08:08:29 UTC
+++ server/inproc_sync.c
@@ -35,8 +35,9 @@
 #include "user.h"
 
 #include "fsync.h"
-
-#include "ntsync_tmp.h"
+#ifdef HAVE_LINUX_NTSYNC_H
+# include <linux/ntsync.h> 
+#endif
 
 #ifdef NTSYNC_IOC_EVENT_READ
 
