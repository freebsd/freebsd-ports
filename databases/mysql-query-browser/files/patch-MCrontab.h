--- mysql-gui-common/source/linux/MCrontab.h.orig	Sat Apr  8 21:17:27 2006
+++ mysql-gui-common/source/linux/MCrontab.h	Sat Apr  8 21:18:01 2006
@@ -41,8 +41,8 @@
   public:
     bool find_entry_by_comment(const std::string &comment, Entry &entry);
 
-    bool MCrontab::remove_entry_with_comment(const std::string &comment,
-                                             const std::string &command="");
+    bool remove_entry_with_comment(const std::string &comment,
+                                   const std::string &command="");
     
     void add_entry(Entry &entry, const std::string &comment);
 
