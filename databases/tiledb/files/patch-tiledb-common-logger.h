--- tiledb/common/logger.h.orig	2021-11-25 02:05:56 UTC
+++ tiledb/common/logger.h
@@ -52,6 +52,7 @@
 #define TILEDB_LOGGER_H
 
 #include <spdlog/spdlog.h>
+#include <spdlog/sinks/stdout_color_sinks.h>
 #include <atomic>
 #include <sstream>
 
