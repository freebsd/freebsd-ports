--- tiledb/common/logger.h.orig	2021-01-07 18:31:04 UTC
+++ tiledb/common/logger.h
@@ -37,6 +37,7 @@
 
 #include <spdlog/fmt/ostr.h>
 #include <spdlog/spdlog.h>
+#include <spdlog/sinks/stdout_color_sinks.h>
 
 #include "tiledb/common/status.h"
 
