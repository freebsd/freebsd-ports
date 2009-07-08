--- untahris.cpp.orig	2009-05-20 01:54:16.000000000 +0400
+++ untahris.cpp	2009-07-07 17:39:06.000000000 +0400
@@ -6,7 +6,7 @@
 
 #include "untahris.h"
 
-char *configfile = "config.unt";
+char *configfile = ".untahris.config";
 
 #include "tools.cpp"
 #include "intface.cpp"
@@ -291,6 +291,8 @@
   }
 
 int main(int argc, char **argv) {
+  chdir(getenv("HOME"));
+
   g.sizeX = 0;
   g.sizeY = 0;
   d.ofsX = 0;
