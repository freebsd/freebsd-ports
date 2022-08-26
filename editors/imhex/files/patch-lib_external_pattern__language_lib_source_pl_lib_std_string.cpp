--- lib/external/pattern_language/lib/source/pl/lib/std/string.cpp.orig	2022-08-14 15:35:34 UTC
+++ lib/external/pattern_language/lib/source/pl/lib/std/string.cpp
@@ -35,7 +35,7 @@ namespace pl::lib::libstd::string {
                 const auto signIndex = index >> (sizeof(index) * 8 - 1);
                 const auto absIndex  = (index ^ signIndex) - signIndex;
 #else
-                const auto absIndex = std::abs(index);
+                const auto absIndex = (unsigned long)std::abs((long)index);
 #endif
 
                 if (absIndex > string.length())
