--- lib/libimhex/source/api/imhex_api.cpp.orig	2023-06-24 10:07:39 UTC
+++ lib/libimhex/source/api/imhex_api.cpp
@@ -8,6 +8,7 @@
 
 #include <wolv/io/file.hpp>
 
+#include <range/v3/algorithm.hpp>
 #include <utility>
 #include <unistd.h>
 
@@ -269,7 +270,7 @@ namespace hex {
         }
 
         bool isDirty() {
-            return std::ranges::any_of(s_providers, [](const auto &provider) {
+            return ranges::any_of(s_providers, [](const auto &provider) {
                 return provider->isDirty();
             });
         }
