Fixes a null pointer dereference, patch origin:
https://github.com/boostorg/filesystem/pull/71
--- libs/filesystem/src/operations.cpp.orig	2018-04-11 13:49:02 UTC
+++ libs/filesystem/src/operations.cpp
@@ -890,20 +890,20 @@ namespace detail
   BOOST_FILESYSTEM_DECL
   void copy(const path& from, const path& to, system::error_code* ec)
   {
-    file_status s(symlink_status(from, *ec));
+    file_status s(detail::symlink_status(from, ec));
     if (ec != 0 && *ec) return;
 
     if(is_symlink(s))
     {
-      copy_symlink(from, to, *ec);
+      detail::copy_symlink(from, to, ec);
     }
     else if(is_directory(s))
     {
-      copy_directory(from, to, *ec);
+      detail::copy_directory(from, to, ec);
     }
     else if(is_regular_file(s))
     {
-      copy_file(from, to, fs::copy_option::fail_if_exists, *ec);
+      detail::copy_file(from, to, detail::fail_if_exists, ec);
     }
     else
     {
