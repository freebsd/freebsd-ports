--- plugins/builtin/source/content/settings_entries.cpp.orig	2022-07-16 11:41:37 UTC
+++ plugins/builtin/source/content/settings_entries.cpp
@@ -19,8 +19,7 @@ namespace {
         userFolders.clear();
         std::vector<std::string> paths = setting;
         for (const auto &path : paths) {
-            // JSON reads char8_t as array, char8_t is not supported as of now
-            std::u8string_view uString(reinterpret_cast<const char8_t *>(&path.front()), reinterpret_cast<const char8_t *>(std::next(&path.back())));
+            std::string_view uString(&path.front()); // This is necessary for Clang13
             userFolders.emplace_back(uString);
         }
     }
