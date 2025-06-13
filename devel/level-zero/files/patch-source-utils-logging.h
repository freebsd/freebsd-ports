--- source/utils/logging.h.orig	2025-05-23 14:18:52 UTC
+++ source/utils/logging.h
@@ -29,11 +29,11 @@
 #include "ze_api.h"
 #include "ze_util.h"
 
-#ifdef __linux__
+#if defined(__FreeBSD__) || defined(__linux__)
 #include <unistd.h>
 #include <sys/types.h>
 #include <pwd.h>
-#endif // __linux__
+#endif // defined(__FreeBSD__) || defined(__linux__)
 
 namespace loader {
 
@@ -235,4 +235,4 @@ inline std::shared_ptr<Logger> createLogger() {
 
 } // namespace loader
 
-#endif
\ No newline at end of file
+#endif
