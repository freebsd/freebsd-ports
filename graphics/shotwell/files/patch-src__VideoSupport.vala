--- src/VideoSupport.vala.orig
+++ src/VideoSupport.vala
@@ -83,8 +83,7 @@
             return ImportResult.UNSUPPORTED_FORMAT;
         }
         
-        TimeVal timestamp;
-        info.get_modification_time(out timestamp);
+        TimeVal timestamp = info.get_modification_time();
         
         // make sure params has a valid md5
         assert(params.md5 != null);
@@ -720,8 +719,7 @@
     }
     
     public void set_master_timestamp(FileInfo info) {
-        TimeVal time_val;
-        info.get_modification_time(out time_val);
+        TimeVal time_val = info.get_modification_time();
         
         try {
             lock (backing_row) {
@@ -1068,8 +1066,7 @@
         if (video.get_filesize() != info.get_size())
             return;
         
-        TimeVal modification;
-        info.get_modification_time(out modification);
+        TimeVal modification = info.get_modification_time();
         
         if (video.get_timestamp() == modification.tv_sec)
             matching_master.add(video);
