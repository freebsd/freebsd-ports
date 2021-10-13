--- tiledb/common/logger.h.orig	2021-09-08 12:12:06 UTC
+++ tiledb/common/logger.h
@@ -52,6 +52,7 @@
 #define TILEDB_LOGGER_H
 
 #include <spdlog/spdlog.h>
+#include <spdlog/sinks/stdout_color_sinks.h>
 #include <sstream>
 
 #include "tiledb/common/heap_memory.h"
