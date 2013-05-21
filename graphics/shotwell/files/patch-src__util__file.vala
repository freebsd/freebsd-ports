--- src/util/file.vala.orig
+++ src/util/file.vala
@@ -155,8 +155,7 @@
     FileInfo info = file.query_info(FILE_ATTRIBUTE_TIME_MODIFIED, FileQueryInfoFlags.NOFOLLOW_SYMLINKS, 
         null);
 
-    TimeVal timestamp = TimeVal();
-    info.get_modification_time(out timestamp);
+    TimeVal timestamp = info.get_modification_time();
     
     return timestamp.tv_sec;
 }
