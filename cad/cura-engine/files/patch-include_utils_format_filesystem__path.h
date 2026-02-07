--- include/utils/format/filesystem_path.h.orig	2024-04-02 12:26:14 UTC
+++ include/utils/format/filesystem_path.h
@@ -30,7 +30,7 @@ struct formatter<std::filesystem::path> : formatter<st
     }
 
     template<typename FormatContext>
-    auto format(const std::filesystem::path& path, FormatContext& ctx)
+    auto format(const std::filesystem::path& path, FormatContext& ctx) const
     {
         return formatter<string_view>::format(anonymizePath(path.generic_string()), ctx);
     }
