--- src/osd/sdl/sdlprefix.h.orig	2015-04-29 06:18:54 UTC
+++ src/osd/sdl/sdlprefix.h
@@ -50,6 +50,7 @@
 #define NO_AFFINITY_NP 1
 #elif defined(__DragonFly__)
 #define SDLMAME_DRAGONFLY 1
+#define NO_AFFINITY_NP 1
 #elif defined(__OpenBSD__)
 #define SDLMAME_OPENBSD 1
 #elif defined(__NetBSD__)
