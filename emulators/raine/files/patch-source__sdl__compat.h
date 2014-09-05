--- source/sdl/compat.h.orig
+++ source/sdl/compat.h
@@ -61,7 +61,7 @@
 #define stricmp strcasecmp
 #define strnicmp strncasecmp
 #endif
-#elif defined(DARWIN)
+#elif defined(DARWIN) || defined(__FreeBSD__)
 #define stricmp strcasecmp
 #define strnicmp strncasecmp
 #endif
