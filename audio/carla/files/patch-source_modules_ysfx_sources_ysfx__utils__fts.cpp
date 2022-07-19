- workaround for https://github.com/jpcima/ysfx/issues/61

--- source/modules/ysfx/sources/ysfx_utils_fts.cpp.orig	2022-07-17 16:50:07 UTC
+++ source/modules/ysfx/sources/ysfx_utils_fts.cpp
@@ -36,7 +36,7 @@ void visit_directories(const char *rootpath, bool (*vi
 #ifndef __EMSCRIPTEN__
     char *argv[] = {(char *)rootpath, nullptr};
 
-    auto compar = [](const FTSENT **a, const FTSENT **b) -> int {
+    auto compar = [](const FTSENT * const *a, const FTSENT * const *b) -> int {
         return strcmp((*a)->fts_name, (*b)->fts_name);
     };
 
