--- src/processor/operator/persistent/writer/parquet/column_writer.cpp.orig	2026-04-05 19:49:57 UTC
+++ src/processor/operator/persistent/writer/parquet/column_writer.cpp
@@ -2,7 +2,7 @@
 
 #include "common/exception/runtime.h"
 #include "function/cast/functions/numeric_limits.h"
-#include "lz4.hpp"
+#include "lz4.h"
 #include "miniz_wrapper.hpp"
 #include "processor/operator/persistent/writer/parquet/boolean_column_writer.h"
 #include "processor/operator/persistent/writer/parquet/interval_column_writer.h"
