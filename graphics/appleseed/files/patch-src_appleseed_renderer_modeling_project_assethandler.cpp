--- src/appleseed/renderer/modeling/project/assethandler.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed/renderer/modeling/project/assethandler.cpp
@@ -80,7 +80,7 @@ namespace
         try
         {
             create_directories(dest_path.parent_path());
-            copy_file(source_path, dest_path, copy_option::overwrite_if_exists);
+            copy_file(source_path, dest_path, copy_options::overwrite_existing);
             return true;
         }
         catch (const std::exception& e)     // namespace qualification required
