--- game/choosestadium.cpp.orig	2008-05-06 17:38:43 UTC
+++ game/choosestadium.cpp
@@ -5,6 +5,7 @@
 #include <fstream>
 #include <sys/stat.h>
 #include <dirent.h>
+#include <unistd.h> // for chdir()
 
 #define THEMES_DIR "themes/"
 
