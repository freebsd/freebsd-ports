--- src/osd/sdl/sdlprefix.h.orig	2018-02-27 15:59:06 UTC
+++ src/osd/sdl/sdlprefix.h
@@ -48,6 +48,7 @@
 #define NO_AFFINITY_NP 1
 #elif defined(__DragonFly__)
 #define SDLMAME_DRAGONFLY 1
+#define NO_AFFINITY_NP 1
 #elif defined(__OpenBSD__)
 #define SDLMAME_OPENBSD 1
 #elif defined(__NetBSD__)
