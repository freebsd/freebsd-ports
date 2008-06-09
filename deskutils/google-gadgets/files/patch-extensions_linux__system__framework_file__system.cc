
$FreeBSD$

--- extensions/linux_system_framework/file_system.cc.orig
+++ extensions/linux_system_framework/file_system.cc
@@ -356,8 +356,8 @@
     if (stat(path_.c_str(), &statbuf))
       return Date(0);
 
-    return Date(statbuf.st_mtim.tv_sec * 1000
-                + statbuf.st_mtim.tv_nsec / 1000000);
+    return Date(statbuf.st_mtimespec.tv_sec * 1000
+                + statbuf.st_mtimespec.tv_nsec / 1000000);
   }
 
   virtual Date GetDateLastAccessed() {
@@ -368,8 +368,8 @@
     if (stat(path_.c_str(), &statbuf))
       return Date(0);
 
-    return Date(statbuf.st_atim.tv_sec * 1000
-                + statbuf.st_atim.tv_nsec / 1000000);
+    return Date(statbuf.st_atimespec.tv_sec * 1000
+                + statbuf.st_atimespec.tv_nsec / 1000000);
   }
 
   virtual int64_t GetSize() {
@@ -646,8 +646,8 @@
     if (stat(path_.c_str(), &statbuf))
       return Date(0);
 
-    return Date(statbuf.st_mtim.tv_sec * 1000
-                + statbuf.st_mtim.tv_nsec / 1000000);
+    return Date(statbuf.st_mtimespec.tv_sec * 1000
+                + statbuf.st_mtimespec.tv_nsec / 1000000);
   }
 
   virtual Date GetDateLastAccessed() {
@@ -658,8 +658,8 @@
     if (stat(path_.c_str(), &statbuf))
       return Date(0);
 
-    return Date(statbuf.st_atim.tv_sec * 1000
-                + statbuf.st_atim.tv_nsec / 1000000);
+    return Date(statbuf.st_atimespec.tv_sec * 1000
+                + statbuf.st_atimespec.tv_nsec / 1000000);
   }
 
   virtual std::string GetType() {
