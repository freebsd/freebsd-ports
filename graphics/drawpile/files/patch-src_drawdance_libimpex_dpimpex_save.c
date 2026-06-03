--- src/drawdance/libimpex/dpimpex/save.c.orig	2025-11-18 11:26:42 UTC
+++ src/drawdance/libimpex/dpimpex/save.c
@@ -1123,7 +1123,7 @@ DP_SaveResult DP_save(DP_CanvasState *cs, DP_DrawConte
 #if defined(_WIN32)
 #    define PREFERRED_PATH_SEPARATOR "\\"
 #    define POSSIBLE_PATH_SEPARATORS "\\/"
-#elif defined(__EMSCRIPTEN__) || defined(__APPLE__) || defined(__linux__) \
+#elif defined(__EMSCRIPTEN__) || defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) \
     || defined(__HAIKU__)
 #    define PREFERRED_PATH_SEPARATOR "/"
 #    define POSSIBLE_PATH_SEPARATORS "/"
