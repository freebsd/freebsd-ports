This revert wine-proton use of an ntsync.h header incompatible with any other OS than Linux

--- dlls/ntdll/unix/sync.c.orig	2026-08-03 08:08:29 UTC
+++ dlls/ntdll/unix/sync.c
@@ -60,8 +60,9 @@
 #ifdef HAVE_KQUEUE
 # include <sys/event.h>
 #endif
-
-# include "ntsync_tmp.h"
+#ifdef HAVE_LINUX_NTSYNC_H
+# include <linux/ntsync.h>
+#endif
 
 #include "ntstatus.h"
 #define WIN32_NO_STATUS
