--- src/enginebuffer.cpp.orig	Fri Jun 25 19:27:39 2004
+++ src/enginebuffer.cpp	Fri Jun 25 19:28:08 2004
@@ -32,6 +32,7 @@
 #include "visual/visualchannel.h"
 #include "mathstuff.h"
 #include "player.h"
+#include "compat_round.h"
 
 
 // Static default values for rate buttons
@@ -361,7 +362,7 @@
     //qDebug("seeking... %f",change);
 
     // Find new playpos
-    double new_playpos = round(change*file_length_old);
+    double new_playpos = compat_round(change*file_length_old);
     if (!even((int)new_playpos))
         new_playpos--;
     if (new_playpos > file_length_old)
@@ -382,7 +383,7 @@
 // Set the cue point at the current play position:
 void EngineBuffer::slotControlCueSet(double)
 {
-    double cue = max(0.,round(filepos_play-Player::getBufferSize()));
+    double cue = max(0.,compat_round(filepos_play-Player::getBufferSize()));
     if (!even((int)cue))
         cue--;
     cuePoint->set(cue);
