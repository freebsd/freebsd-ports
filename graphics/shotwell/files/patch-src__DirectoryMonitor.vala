--- src/DirectoryMonitor.vala.orig
+++ src/DirectoryMonitor.vala
@@ -276,8 +276,7 @@
             
             // get all the interesting matchable items from the supplied FileInfo
             int64 match_size = match.get_size();
-            TimeVal match_time;
-            match.get_modification_time(out match_time);
+            TimeVal match_time = match.get_modification_time();
             
             foreach (File file in map.keys) {
                 FileInfo info = map.get(file);
@@ -290,8 +289,7 @@
                 if (match_size != info.get_size())
                     continue;
                 
-                TimeVal time;
-                info.get_modification_time(out time);
+                TimeVal time = info.get_modification_time();
                 
                 if (time.tv_sec != match_time.tv_sec)
                     continue;
