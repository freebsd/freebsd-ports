--- sql/mdl_context_backup.h.orig	2025-08-19 10:30:31 UTC
+++ sql/mdl_context_backup.h
@@ -49,7 +49,7 @@ class MDL_context_backup_manager {
     Key for uniquely identifying MDL_context in the MDL_context_backup map.
   */
   using MDL_context_backup_key =
-      std::basic_string<uchar, my_char_traits<uchar>>;
+      std::vector<uchar>;
 
   class MDL_context_backup;
 
