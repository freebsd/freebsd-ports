--- src/processor/operator/persistent/reader/parquet/column_reader.cpp.orig	2026-04-05 19:50:13 UTC
+++ src/processor/operator/persistent/reader/parquet/column_reader.cpp
@@ -7,7 +7,7 @@
 #include "common/exception/not_implemented.h"
 #include "common/exception/runtime.h"
 #include "common/types/date_t.h"
-#include "lz4.hpp"
+#include "lz4.h"
 #include "miniz_wrapper.hpp"
 #include "processor/operator/persistent/reader/parquet/boolean_column_reader.h"
 #include "processor/operator/persistent/reader/parquet/callback_column_reader.h"
