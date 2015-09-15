--- utilities/checkpoint/checkpoint.cc.orig	2015-08-31 18:23:39 UTC
+++ utilities/checkpoint/checkpoint.cc
@@ -131,7 +131,7 @@ Status CheckpointImpl::CreateCheckpoint(
                    (type == kDescriptorFile) ? manifest_file_size : 0);
     }
   }
-  Log(db_->GetOptions().info_log, "Number of log files %ld",
+  Log(db_->GetOptions().info_log, "Number of log files %zu",
       live_wal_files.size());
 
   // Link WAL files. Copy exact size of last one because it is the only one
