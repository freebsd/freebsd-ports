--- RunController.cpp.orig	2011-08-28 20:02:12.000000000 +0200
+++ RunController.cpp	2011-08-28 20:02:22.000000000 +0200
@@ -56,7 +56,7 @@
 
 
 #ifdef LINUX_ESPEAK
-	#include <speak_lib.h>
+	#include <espeak/speak_lib.h>
 #endif
 
 #ifdef LINUX_FLITE
