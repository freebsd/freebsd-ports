$FreeBSD$

--- src/s_stuff.h.orig	Thu Jul 31 18:26:16 2003
+++ src/s_stuff.h	Tue Nov 11 21:50:10 2003
@@ -131,10 +131,8 @@
 #define API_PORTAUDIO 4
 #define API_JACK 5
 
-#ifdef __linux__
 #define API_DEFAULT API_OSS
 #define API_DEFSTRING "OSS"
-#endif
 #ifdef MSW
 #define API_DEFAULT API_MMIO
 #define API_DEFSTRING "MMIO"
