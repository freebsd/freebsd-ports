--- folly/portability/Stdlib.h.orig	2020-05-27 18:53:42 UTC
+++ folly/portability/Stdlib.h
@@ -52,7 +52,7 @@ char*** _NSGetEnviron(void);
 
 #if defined(__FreeBSD__)
 // Needed to resolve linkage
-char** environ;
+extern char** environ;
 #endif
 
 #if !__linux__ && !FOLLY_MOBILE
