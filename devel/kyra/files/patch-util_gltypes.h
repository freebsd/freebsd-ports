--- util/gltypes.h.orig	Tue Sep 12 19:01:55 2006
+++ util/gltypes.h	Tue Sep 12 19:02:26 2006
@@ -40,8 +40,8 @@
 	typedef Sint32			S32;
 
 	#ifdef SDL_HAS_64BIT_TYPE
-		typedef SDL_HAS_64BIT_TYPE				S64;
-		typedef unsigned SDL_HAS_64BIT_TYPE		U64;
+		typedef Sint64		S64;
+		typedef Uint64		U64;
 	#else
 		#error No 64-bit integer.
 	#endif
