--- src/util/optional.h.orig	2023-10-30 12:11:18 UTC
+++ src/util/optional.h
@@ -11,20 +11,20 @@ Author: Diffblue Ltd.
 #define CPROVER_UTIL_OPTIONAL_H
 
 #if defined __clang__
-  #pragma clang diagnostic push ignore "-Wall"
-  #pragma clang diagnostic push ignore "-Wpedantic"
+  #pragma clang diagnostic push
+  #pragma clang diagnostic ignored "-Wall"
+  #pragma clang diagnostic ignored "-Wpedantic"
 #elif defined __GNUC__
-  #pragma GCC diagnostic push ignore "-Wall"
-  #pragma GCC diagnostic push ignore "-Wpedantic"
+  #pragma GCC diagnostic push
+  #pragma GCC diagnostic ignored "-Wall"
+  #pragma GCC diagnostic ignored "-Wpedantic"
 #elif defined _MSC_VER
   #pragma warning(push)
 #endif
 #include <nonstd/optional.hpp>
 #if defined  __clang__
   #pragma clang diagnostic pop
-  #pragma clang diagnostic pop
 #elif defined  __GNUC__
-  #pragma GCC diagnostic pop
   #pragma GCC diagnostic pop
 #elif defined _MSC_VER
   #pragma warning(pop)
