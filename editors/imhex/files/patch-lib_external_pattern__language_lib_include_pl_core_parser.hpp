--- lib/external/pattern_language/lib/include/pl/core/parser.hpp.orig	2023-05-21 11:04:34 UTC
+++ lib/external/pattern_language/lib/include/pl/core/parser.hpp
@@ -234,7 +234,7 @@ namespace pl::core {
             else if constexpr (S == Not)
                 return false;
             else
-                std::unreachable();
+                __builtin_unreachable();
         }
 
         template<Setting S = Normal>
@@ -265,7 +265,7 @@ namespace pl::core {
                 partReset();
                 return false;
             } else
-                std::unreachable();
+                __builtin_unreachable();
         }
 
         template<Setting S = Normal>
@@ -280,7 +280,7 @@ namespace pl::core {
             else if constexpr (S == Not)
                 return true;
             else
-                std::unreachable();
+                __builtin_unreachable();
         }
 
         template<Setting S = Normal>
@@ -290,7 +290,7 @@ namespace pl::core {
             else if constexpr (S == Not)
                 return sequenceImpl<Not>(token) && oneOfImpl(args...);
             else
-                std::unreachable();
+                __builtin_unreachable();
         }
 
         template<Setting S = Normal>
