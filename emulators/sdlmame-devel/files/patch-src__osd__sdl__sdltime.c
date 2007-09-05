--- ./src/osd/sdl/sdltime.c.orig	Tue Jul 10 13:43:47 2007
+++ ./src/osd/sdl/sdltime.c	Wed Aug 29 00:49:36 2007
@@ -34,7 +34,7 @@
 
 
 // cheez until u3
-#if defined(LSB_FIRST) && !defined(PTR64)
+#ifdef __i386__
 #define X86_ASM
 #endif
 
