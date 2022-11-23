--- lib/external/libromfs/generator/source/main.cpp.orig	2022-11-23 12:47:55 UTC
+++ lib/external/libromfs/generator/source/main.cpp
@@ -87,7 +87,7 @@ int main() {
         for (std::uint64_t i = 0; i < identifierCount; i++) {
             std::printf("libromfs: Bundling resource: %s\n", paths[i].string().c_str());
 
-            outputFile << "    " << "{ \"" << paths[i].string() << "\", romfs::Resource({ reinterpret_cast<std::byte*>(resource_" LIBROMFS_PROJECT_NAME "_" << i << ".data()), " << "resource_" LIBROMFS_PROJECT_NAME "_" << i << ".size() }) " << "},\n";
+            outputFile << "    " << "{ \"" << paths[i].string() << "\", romfs::Resource({ reinterpret_cast<std::byte*>(resource_" LIBROMFS_PROJECT_NAME "_" << i << ".data()), " << "resource_" LIBROMFS_PROJECT_NAME "_" << i << ".size() - 1 }) " << "},\n";
         }
         outputFile << "};";
     }
