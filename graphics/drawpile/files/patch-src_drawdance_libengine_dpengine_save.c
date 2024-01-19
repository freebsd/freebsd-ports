--- src/drawdance/libengine/dpengine/save.c.orig	2024-01-14 11:13:49 UTC
+++ src/drawdance/libengine/dpengine/save.c
@@ -832,7 +832,7 @@ DP_SaveResult DP_save(DP_CanvasState *cs, DP_DrawConte
 #if defined(_WIN32)
 #    define PREFERRED_PATH_SEPARATOR "\\"
 #    define POSSIBLE_PATH_SEPARATORS "\\/"
-#elif defined(__EMSCRIPTEN__) || defined(__APPLE__) || defined(__linux__)
+#elif defined(__EMSCRIPTEN__) || defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
 #    define PREFERRED_PATH_SEPARATOR "/"
 #    define POSSIBLE_PATH_SEPARATORS "/"
 #else
