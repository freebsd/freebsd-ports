--- src/usages_clang.cpp.orig	2023-08-03 07:43:31 UTC
+++ src/usages_clang.cpp
@@ -562,7 +562,7 @@ Usages::Clang::PathSet Usages::Clang::find_paths(const
     boost::system::error_code ec;
     if(!boost::filesystem::is_regular_file(path, ec)) {
       if(path == build_path || path == debug_path || path.filename() == ".git")
-        it.no_push();
+        it.disable_recursion_pending();
       continue;
     }
 
@@ -737,7 +737,7 @@ void Usages::Clang::write_cache(const boost::filesyste
       stream.close();
       boost::filesystem::rename(tmp_file, full_cache_path, ec);
       if(ec) {
-        boost::filesystem::copy_file(tmp_file, full_cache_path, boost::filesystem::copy_option::overwrite_if_exists);
+        boost::filesystem::copy_file(tmp_file, full_cache_path, boost::filesystem::copy_options::overwrite_existing);
         boost::filesystem::remove(tmp_file, ec);
       }
     }
@@ -759,9 +759,9 @@ Usages::Clang::Cache Usages::Clang::read_cache(const b
   if(boost::filesystem::exists(cache_path, ec)) {
     std::ifstream stream(cache_path.string());
     if(stream) {
-      Cache cache;
-      boost::archive::text_iarchive text_iarchive(stream);
       try {
+        Cache cache;
+        boost::archive::text_iarchive text_iarchive(stream);
         text_iarchive >> cache;
         return cache;
       }
