--- lib/libimhex/source/api/project_file_manager.cpp.orig	2023-04-04 10:04:22 UTC
+++ lib/libimhex/source/api/project_file_manager.cpp
@@ -46,7 +46,7 @@ namespace hex {
                 return false;
         }
 
-        auto providers = auto(ImHexApi::Provider::getProviders());
+        auto providers = ImHexApi::Provider::getProviders();
         for (const auto &provider : providers) {
             ImHexApi::Provider::remove(provider);
         }
