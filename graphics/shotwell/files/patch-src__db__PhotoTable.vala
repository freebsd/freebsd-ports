--- src/db/PhotoTable.vala.orig
+++ src/db/PhotoTable.vala
@@ -1034,8 +1034,7 @@
         if (filesize != info.get_size())
             return false;
         
-        TimeVal modification;
-        info.get_modification_time(out modification);
+        TimeVal modification = info.get_modification_time();
         
         return timestamp == modification.tv_sec;
     }
@@ -1044,8 +1043,7 @@
         if (filesize != info.get_size())
             return false;
         
-        TimeVal modification;
-        info.get_modification_time(out modification);
+        TimeVal modification = info.get_modification_time();
         
         return timestamp != modification.tv_sec;
     }
