--- include/SDL_stdinc.h.orig	2006-06-27 00:48:32.000000000 -0400
+++ include/SDL_stdinc.h	2008-01-27 12:47:15.000000000 -0500
@@ -319,6 +319,7 @@
 	__asm__ __volatile__ (				\
 		"std\n\t"				\
 		"rep ; movsl\n\t"			\
+		"cld\n\t"				\
 		: "=&c" (u0), "=&D" (u1), "=&S" (u2)	\
 		: "0" (n >> 2),				\
 		  "1" (dstp+(n-4)), "2" (srcp+(n-4))	\
