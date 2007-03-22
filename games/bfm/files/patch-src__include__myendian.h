--- ./src/include/myendian.h.orig	Thu Apr 14 12:09:25 2005
+++ ./src/include/myendian.h	Thu Mar 22 10:53:40 2007
@@ -102,7 +102,7 @@
 
 #else
 
-#define FetchLE16(p) SDL_SwapLE16(*((unsigned short*)(p))++)
+inline Uint16 FetchLE16(Uint16 **p);
 
 #endif
 
@@ -122,7 +122,7 @@
 
 #else
 
-#define FetchLE32(p) SDL_SwapLE32(*((unsigned int*)(p))++)
+inline Uint32 FetchLE32(Uint32 **p);
 
 #endif
 
