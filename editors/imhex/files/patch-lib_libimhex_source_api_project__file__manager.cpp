--- lib/libimhex/source/api/project_file_manager.cpp.orig	2023-02-13 15:22:20 UTC
+++ lib/libimhex/source/api/project_file_manager.cpp
@@ -43,7 +43,7 @@ namespace hex {
                 return false;
         }
 
-        auto providers = auto(ImHexApi::Provider::getProviders());
+        auto providers = ImHexApi::Provider::getProviders();
         for (const auto &provider : providers) {
             ImHexApi::Provider::remove(provider);
         }
