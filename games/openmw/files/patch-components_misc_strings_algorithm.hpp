--- components/misc/strings/algorithm.hpp.orig	2025-07-01 11:41:15 UTC
+++ components/misc/strings/algorithm.hpp
@@ -4,6 +4,7 @@
 #include "lower.hpp"
 
 #include <algorithm>
+#include <cstdint>
 #include <functional>
 #include <string>
 #include <string_view>
@@ -88,14 +89,14 @@ namespace Misc::StringUtils
         constexpr std::size_t operator()(std::string_view str) const
         {
             // FNV-1a
-            std::size_t hash{ 0xcbf29ce484222325ull };
-            constexpr std::size_t prime{ 0x00000100000001B3ull };
+            std::uint64_t hash{ 0xcbf29ce484222325ull };
+            constexpr std::uint64_t prime{ 0x00000100000001B3ull };
             for (char c : str)
             {
-                hash ^= static_cast<std::size_t>(toLower(c));
+                hash ^= static_cast<std::uint64_t>(toLower(c));
                 hash *= prime;
             }
-            return hash;
+            return static_cast<std::size_t>(hash);
         }
     };
