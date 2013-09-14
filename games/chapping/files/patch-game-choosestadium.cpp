--- game/choosestadium.cpp.orig	2013-09-13 21:14:11.171227695 +0400
+++ game/choosestadium.cpp	2013-09-13 21:14:29.875227107 +0400
@@ -5,6 +5,7 @@
 #include <fstream>
 #include <sys/stat.h>
 #include <dirent.h>
+#include <unistd.h> // for chdir()
 
 #define THEMES_DIR "/home/amdmi3/projects/freebsd/ports/games/chapping/prefix/share/chapping/themes/"
 
