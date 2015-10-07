Obtained from:	https://github.com/facebook/rocksdb/commit/f171faa240ccd12ac05d54b7ea0a8c29d2f1d9d6

--- utilities/checkpoint/checkpoint.cc.orig	2015-08-31 18:23:39 UTC
+++ utilities/checkpoint/checkpoint.cc
@@ -24,6 +24,7 @@
 #include "rocksdb/env.h"
 #include "rocksdb/transaction_log.h"
 #include "util/file_util.h"
+#include "port/port.h"
 
 namespace rocksdb {
 
@@ -131,7 +132,7 @@ Status CheckpointImpl::CreateCheckpoint(
                    (type == kDescriptorFile) ? manifest_file_size : 0);
     }
   }
-  Log(db_->GetOptions().info_log, "Number of log files %ld",
+  Log(db_->GetOptions().info_log, "Number of log files %" ROCKSDB_PRIszt,
       live_wal_files.size());
 
   // Link WAL files. Copy exact size of last one because it is the only one
