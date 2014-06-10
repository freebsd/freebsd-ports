--- sound_files.cpp.orig	2007-11-06 00:08:33.000000000 +0100
+++ sound_files.cpp	2007-11-06 00:08:45.000000000 +0100
@@ -22,7 +22,7 @@
 
 #include "defs.h"
 
-char *soundFiles[] = {
+const char *soundFiles[] = {
 	DATA_DIR PATHSEP "sound" PATHSEP "block_ball.wav",
 	DATA_DIR PATHSEP "sound" PATHSEP "bonus_life.wav",
 	DATA_DIR PATHSEP "sound" PATHSEP "catch_ball.wav",
