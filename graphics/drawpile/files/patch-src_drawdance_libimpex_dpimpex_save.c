--- src/drawdance/libimpex/dpimpex/save.c.orig	2025-03-27 05:51:37 UTC
+++ src/drawdance/libimpex/dpimpex/save.c
@@ -884,7 +884,7 @@ DP_SaveResult DP_save(DP_CanvasState *cs, DP_DrawConte
 #if defined(_WIN32)
 #    define PREFERRED_PATH_SEPARATOR "\\"
 #    define POSSIBLE_PATH_SEPARATORS "\\/"
-#elif defined(__EMSCRIPTEN__) || defined(__APPLE__) || defined(__linux__)
+#elif defined(__EMSCRIPTEN__) || defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
 #    define PREFERRED_PATH_SEPARATOR "/"
 #    define POSSIBLE_PATH_SEPARATORS "/"
 #else
