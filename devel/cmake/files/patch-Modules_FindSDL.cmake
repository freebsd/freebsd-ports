--- Modules/FindSDL.cmake.orig	2009-11-13 21:32:52.000000000 +0300
+++ Modules/FindSDL.cmake	2010-01-28 17:32:40.000000000 +0300
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
@@ -100,7 +105,7 @@
 #MESSAGE("SDL_LIBRARY_TEMP is ${SDL_LIBRARY_TEMP}")
 
 IF(NOT SDL_BUILDING_LIBRARY)
-  IF(NOT ${SDL_INCLUDE_DIR} MATCHES ".framework")
+  IF(NOT "${SDL_INCLUDE_DIR}" MATCHES ".framework")
     # Non-OS X framework versions expect you to also dynamically link to 
     # SDLmain. This is mainly for Windows and OS X. Other (Unix) platforms 
     # seem to provide SDLmain for compatibility even though they don't
@@ -116,7 +121,7 @@
       /opt/csw
       /opt
     )
-  ENDIF(NOT ${SDL_INCLUDE_DIR} MATCHES ".framework")
+  ENDIF(NOT "${SDL_INCLUDE_DIR}" MATCHES ".framework")
 ENDIF(NOT SDL_BUILDING_LIBRARY)
 
 # SDL may require threads on your system.
