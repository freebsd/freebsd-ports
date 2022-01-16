--- plugins/builtin/source/content/pl_builtin_functions.cpp.orig	2022-01-12 08:17:14 UTC
+++ plugins/builtin/source/content/pl_builtin_functions.cpp
@@ -209,7 +209,7 @@ namespace hex::plugin::builtin {
                     const auto signIndex = index >> (sizeof(index) * 8 - 1);
                     const auto absIndex = (index ^ signIndex) - signIndex;
                 #else
-                    const auto absIndex = std::abs(index);
+                    const auto absIndex = std::abs((long)index);
                 #endif
 
                 if (absIndex > string.length())
