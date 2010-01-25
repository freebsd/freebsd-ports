--- ./Modules/FindSDL.cmake.orig	2009-11-13 21:32:52.000000000 +0300
+++ ./Modules/FindSDL.cmake	2010-01-25 22:23:16.749128606 +0300
@@ -81,6 +81,11 @@
   /opt/csw # Blastwave
   /opt
 )
+#On FreeBSD SDL depends on libiconv and SDL_stdinc.h includes iconv.h, which is
+#located in ${LOCALBASE}/include. Append {LOCALBASE}/include to
+#the SDL_INCLUDE_DIR, thus allow to build SDL apps out of box.
+LIST(APPEND SDL_INCLUDE_DIR /usr/local/include)
+
 #MESSAGE("SDL_INCLUDE_DIR is ${SDL_INCLUDE_DIR}")
 
 # SDL-1.1 is the name used by FreeBSD ports...
