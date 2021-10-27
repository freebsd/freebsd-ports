--- ../grinliz/glperformance.h.orig	2021-10-26 01:06:25.780070000 +0200
+++ ../grinliz/glperformance.h	2021-10-26 01:16:02.969577000 +0200
@@ -34,6 +34,8 @@
 #include "gltypes.h"
 #include "gldebug.h"
 
+#include <SDL/SDL_timer.h>
+
 namespace grinliz {
 
 const int GL_MAX_PROFILE_DATAITEM = 64;
@@ -91,7 +93,7 @@
 #else
 	inline U64 FastTime()
 	{
-		#ifdef __GNUC__
+		#if defined(__GNUC__) && (defined(__amd64__) || defined(__i386__))
 			U64 val;
     		 __asm__ __volatile__ ("rdtsc" : "=A" (val));
     		 return val;
