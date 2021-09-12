- workaround for missing S_IRUSR,etc, see https://github.com/OpenTimer/OpenTimer/issues/46

--- ot/utility/logger.hpp.orig	2021-09-12 22:40:42 UTC
+++ ot/utility/logger.hpp
@@ -13,6 +13,7 @@
 #include <mutex>
 #include <fcntl.h>
 #include <unistd.h>
+#include <sys/stat.h>
 
 namespace ot {
 
