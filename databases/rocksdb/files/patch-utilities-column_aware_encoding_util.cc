--- utilities/column_aware_encoding_util.cc.orig	2017-08-30 21:26:12 UTC
+++ utilities/column_aware_encoding_util.cc
@@ -25,6 +25,7 @@
 #include "table/block_based_table_factory.h"
 #include "table/format.h"
 #include "table/table_reader.h"
+#include "util/cast_util.h"
 #include "util/coding.h"
 #include "utilities/col_buf_decoder.h"
 #include "utilities/col_buf_encoder.h"
@@ -58,7 +59,7 @@ void ColumnAwareEncodingReader::InitTabl
                          /*skip_filters=*/false),
       std::move(file_), file_size, &table_reader, /*enable_prefetch=*/false);
 
-  table_reader_.reset(dynamic_cast<BlockBasedTable*>(table_reader.release()));
+  table_reader_.reset(static_cast_with_check<BlockBasedTable, TableReader>(table_reader.release()));
 }
 
 void ColumnAwareEncodingReader::GetKVPairsFromDataBlocks(
