--- lib/external/pattern_language/lib/source/pl/libstd/string.cpp.orig	2022-07-05 14:26:01 UTC
+++ lib/external/pattern_language/lib/source/pl/libstd/string.cpp
@@ -33,7 +33,7 @@ namespace pl::libstd::string {
                 const auto signIndex = index >> (sizeof(index) * 8 - 1);
                 const auto absIndex  = (index ^ signIndex) - signIndex;
 #else
-                const auto absIndex = std::abs(index);
+                const auto absIndex = (unsigned long)std::abs((long)index);
 #endif
 
                 if (absIndex > string.length())
