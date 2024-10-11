--- src/cpp/shared_core/FilePath.cpp.orig	2024-10-10 05:51:04 UTC
+++ src/cpp/shared_core/FilePath.cpp
@@ -805,9 +805,9 @@ Error FilePath::copy(const FilePath& in_targetPath, bo
 {
    try
    {
-      boost::filesystem::copy_option::enum_type option = overwrite
-         ? boost::filesystem::copy_option::overwrite_if_exists
-         : boost::filesystem::copy_option::fail_if_exists;
+      boost::filesystem::copy_options option = overwrite
+         ? boost::filesystem::copy_options::overwrite_existing
+         : boost::filesystem::copy_options::none;
       boost::filesystem::copy_file(m_impl->Path, in_targetPath.m_impl->Path, option);
       return Success();
    }
