--- untahris.cpp.orig	2009-05-20 01:54:16.000000000 +0400
+++ untahris.cpp	2013-09-13 21:12:51.205227100 +0400
@@ -4,9 +4,12 @@
 // --------------------------------------------------------------
 // Main file.
 
+#include <unistd.h>
+#include <time.h>
+
 #include "untahris.h"
 
-char *configfile = "config.unt";
+char *configfile = ".untahris.config";
 
 #include "tools.cpp"
 #include "intface.cpp"
@@ -291,6 +294,8 @@
   }
 
 int main(int argc, char **argv) {
+  chdir(getenv("HOME"));
+
   g.sizeX = 0;
   g.sizeY = 0;
   d.ofsX = 0;
