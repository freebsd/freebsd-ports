--- sandbox/linux/services/init_process_reaper.cc.orig	2025-03-24 20:50:14 UTC
+++ sandbox/linux/services/init_process_reaper.cc
@@ -7,6 +7,7 @@
 #pragma allow_unsafe_libc_calls
 #endif
 
+#if 0
 #include "sandbox/linux/services/init_process_reaper.h"
 
 #include <signal.h>
@@ -105,3 +106,4 @@ bool CreateInitProcessReaper(base::OnceClosure post_fo
 }
 
 }  // namespace sandbox.
+#endif
