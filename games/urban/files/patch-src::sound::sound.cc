--- src/sound/sound.cc.orig	Tue Dec 14 06:29:12 2004
+++ src/sound/sound.cc	Tue Dec 14 06:29:21 2004
@@ -28,6 +28,7 @@
 
     thomas.nyberg@usa.net				jonas_b@bitsmart.com
 *****************************************************************************/
+#include <unistd.h>
 #include <allegro.h>
 #ifdef DJGPP
   #include <jgmod.h>
