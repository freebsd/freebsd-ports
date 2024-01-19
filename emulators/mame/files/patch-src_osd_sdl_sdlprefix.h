 FreeBSD supports pthread affinity: pthread_affinity_np(3).

--- src/osd/sdl/sdlprefix.h.orig	2022-04-29 05:37:26 UTC
+++ src/osd/sdl/sdlprefix.h
@@ -45,9 +45,9 @@
 
 #elif defined(__FreeBSD__)
 #define SDLMAME_FREEBSD 1
-#define NO_AFFINITY_NP 1
 #elif defined(__DragonFly__)
 #define SDLMAME_DRAGONFLY 1
+#define NO_AFFINITY_NP 1
 #elif defined(__OpenBSD__)
 #define SDLMAME_OPENBSD 1
 #elif defined(__NetBSD__)
