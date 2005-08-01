--- gtkpool/sound.cpp.orig	Mon Jul 29 04:57:41 2002
+++ gtkpool/sound.cpp	Fri Jul 29 19:06:47 2005
@@ -26,7 +26,7 @@
 #include <errno.h>
 #include "sound.h"
 
-SoundError::SoundError(char *desc, int c, int r = 0, int g = 0){
+SoundError::SoundError(char *desc, int c, int r, int g){
 	description = strdup(desc);
 	code = c;
 	requested = r;
