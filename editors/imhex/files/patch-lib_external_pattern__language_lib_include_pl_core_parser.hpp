--- lib/external/pattern_language/lib/include/pl/core/parser.hpp.orig	2023-04-08 16:22:09 UTC
+++ lib/external/pattern_language/lib/include/pl/core/parser.hpp
@@ -233,7 +233,7 @@ namespace pl::core {
             else if constexpr (S == Not)
                 return false;
             else
-                std::unreachable();
+                __builtin_unreachable();
         }
 
         template<Setting S = Normal>
@@ -264,7 +264,7 @@ namespace pl::core {
                 partReset();
                 return false;
             } else
-                std::unreachable();
+                __builtin_unreachable();
         }
 
         template<Setting S = Normal>
@@ -279,7 +279,7 @@ namespace pl::core {
             else if constexpr (S == Not)
                 return true;
             else
-                std::unreachable();
+                __builtin_unreachable();
         }
 
         template<Setting S = Normal>
@@ -289,7 +289,7 @@ namespace pl::core {
             else if constexpr (S == Not)
                 return sequenceImpl<Not>(token) && oneOfImpl(args...);
             else
-                std::unreachable();
+                __builtin_unreachable();
         }
 
         template<Setting S = Normal>
