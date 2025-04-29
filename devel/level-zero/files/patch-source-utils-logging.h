--- source/utils/logging.h.orig	2025-04-10 20:05:03 UTC
+++ source/utils/logging.h
@@ -29,11 +29,9 @@
 #include "ze_api.h"
 #include "ze_util.h"
 
-#ifdef __linux__
 #include <unistd.h>
 #include <sys/types.h>
 #include <pwd.h>
-#endif // __linux__
 
 namespace loader {
 
@@ -235,4 +233,4 @@ inline std::shared_ptr<Logger> createLogger() {
 
 } // namespace loader
 
-#endif
\ No newline at end of file
+#endif
