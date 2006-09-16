--- untahris.cpp.orig	Tue Sep  5 16:50:04 2006
+++ untahris.cpp	Fri Sep  8 06:54:50 2006
@@ -6,7 +6,7 @@
 
 #include "untahris.h"
 
-char *configfile = "config.unt";
+char *configfile = ".untahris.config";
 
 #include "tools.cpp"
 #include "intface.cpp"
@@ -117,6 +117,7 @@
   }
 
 int main(int argc, char **argv) {
+	chdir(getenv("HOME"));
   g.sizeX = 0;
   g.sizeY = 0;
   d.ofsX = 0;
