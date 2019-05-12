--- tiledb/sm/misc/logger.h.orig	2019-04-02 19:10:07 UTC
+++ tiledb/sm/misc/logger.h
@@ -37,6 +37,7 @@
 
 #include <spdlog/fmt/ostr.h>
 #include <spdlog/spdlog.h>
+#include <spdlog/sinks/stdout_color_sinks.h>
 
 #include "tiledb/sm/misc/status.h"
 
