--- Modules/FindSDL.cmake.orig	2012-04-18 22:24:55.000000000 -0300
+++ Modules/FindSDL.cmake	2012-04-18 22:26:06.000000000 -0300
@@ -82,6 +82,11 @@
   /opt
 )
 
+# On FreeBSD SDL depends on libiconv and SDL_stdinc.h includes iconv.h, which is
+# located in ${LOCALBASE}/include. Append {LOCALBASE}/include to
+# the SDL_INCLUDE_DIR, thus allow to build SDL apps out of box.
+LIST(APPEND SDL_INCLUDE_DIR /usr/local/include)
+
 # SDL-1.1 is the name used by FreeBSD ports...
 # don't confuse it for the version number.
 FIND_LIBRARY(SDL_LIBRARY_TEMP 
@@ -97,7 +102,7 @@
 )
 
 IF(NOT SDL_BUILDING_LIBRARY)
-  IF(NOT ${SDL_INCLUDE_DIR} MATCHES ".framework")
+  IF(NOT "${SDL_INCLUDE_DIR}" MATCHES ".framework")
     # Non-OS X framework versions expect you to also dynamically link to 
     # SDLmain. This is mainly for Windows and OS X. Other (Unix) platforms 
     # seem to provide SDLmain for compatibility even though they don't
@@ -113,7 +118,7 @@
       /opt/csw
       /opt
     )
-  ENDIF(NOT ${SDL_INCLUDE_DIR} MATCHES ".framework")
+  ENDIF(NOT "${SDL_INCLUDE_DIR}" MATCHES ".framework")
 ENDIF(NOT SDL_BUILDING_LIBRARY)
 
 # SDL may require threads on your system.
