--- toycars/src/HotPotatoGame.cpp.orig	2009-03-21 14:17:43.000000000 +0300
+++ toycars/src/HotPotatoGame.cpp	2013-09-14 07:52:54.279227416 +0400
@@ -18,13 +18,7 @@
 #include "glf.h"
 #include "TcPreferences.h"
 
-/* When using MINGW (-mno-cygwin), srandom/random isn't defined */
-#ifndef seed48
-unsigned short * seed48(unsigned short xseed[3]);
-#endif
-#ifndef drand48
-double drand48();
-#endif
+#include <stdlib.h>
 
 const double kExplosionSoundFrequency = 44.1e3;	// Hz
 
