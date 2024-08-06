Fall back to fast_float when C++ stdlib doesn't provide from_chars for floats

See also:
https://github.com/aardappel/treesheets/issues/686
https://github.com/Stellarium/stellarium/issues/3656

--- lobster/src/lobster/string_tools.h.orig	2024-08-06 08:52:45 UTC
+++ lobster/src/lobster/string_tools.h
@@ -157,7 +157,7 @@ template<typename T> T parse_float(string_view sv, con
 
 template<typename T> T parse_float(string_view sv, const char **end = nullptr) {
     // FIXME: Upgrade compilers for these platforms on CI.
-    #if defined(__APPLE__) || defined(__ANDROID__) || defined(__EMSCRIPTEN__)
+    #if defined(__APPLE__) || defined(__ANDROID__) || defined(__EMSCRIPTEN__) || defined(__FreeBSD__)
         auto &term = *(char *)(sv.data() + sv.size());
         auto orig = term;
         term = 0;
