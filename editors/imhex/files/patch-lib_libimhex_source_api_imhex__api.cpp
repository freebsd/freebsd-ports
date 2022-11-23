--- lib/libimhex/source/api/imhex_api.cpp.orig	2022-11-14 09:07:21 UTC
+++ lib/libimhex/source/api/imhex_api.cpp
@@ -4,6 +4,7 @@
 #include <hex/api/event.hpp>
 #include <hex/providers/provider.hpp>
 
+#include <range/v3/algorithm.hpp>
 #include <utility>
 #include <unistd.h>
 
@@ -272,7 +273,7 @@ namespace hex {
         }
 
         bool isDirty() {
-            return std::ranges::any_of(s_providers, [](const auto &provider) {
+            return ranges::any_of(s_providers, [](const auto &provider) {
                 return provider->isDirty();
             });
         }
