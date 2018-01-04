--- src/cpp/core/include/core/r_util/RTokenizer.hpp.orig	2017-11-16 21:40:37 UTC
+++ src/cpp/core/include/core/r_util/RTokenizer.hpp
@@ -35,7 +35,7 @@
 
 // On Linux confirm that wchar_t is Unicode
 #if !defined(_WIN32) && !defined(__APPLE__) && !defined(__STDC_ISO_10646__)
-   #error "wchar_t is not Unicode"
+//   #error "wchar_t is not Unicode"
 #endif
 
 namespace rstudio {
