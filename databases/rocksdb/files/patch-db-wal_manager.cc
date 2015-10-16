--- db/wal_manager.cc.orig	2015-08-31 20:23:39.000000000 +0200
+++ db/wal_manager.cc	2015-09-07 23:52:03.849468000 +0200
@@ -329,8 +329,8 @@ Status WalManager::GetSortedWalsOfType(c
         return s;
       }
 
-      log_files.push_back(std::move(std::unique_ptr<LogFile>(
-          new LogFileImpl(number, log_type, sequence, size_bytes))));
+      log_files.push_back(std::unique_ptr<LogFile>(
+          new LogFileImpl(number, log_type, sequence, size_bytes)));
     }
   }
   CompareLogByPointer compare_log_files;
