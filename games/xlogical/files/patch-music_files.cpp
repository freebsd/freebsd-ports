--- music_files.cpp.orig	2007-11-06 00:07:45.000000000 +0100
+++ music_files.cpp	2007-11-06 00:08:06.000000000 +0100
@@ -22,7 +22,7 @@
 
 #include "defs.h"
 
-char *musicFiles[] = {
+const char *musicFiles[] = {
 	DATA_DIR PATHSEP "music" PATHSEP "intro.mod",
 	DATA_DIR PATHSEP "music" PATHSEP "pregame.mod",
 	DATA_DIR PATHSEP "music" PATHSEP "ingame.mod",
