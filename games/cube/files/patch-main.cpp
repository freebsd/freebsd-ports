--- source/src/main.old	Thu Oct 17 22:27:33 2002
+++ source/src/main.cpp	Thu Oct 17 22:58:12 2002
@@ -1,6 +1,7 @@
 // main.cpp: initialisation & main loop
 
 #include "cube.h"
+#include <unistd.h>
 
 void cleanup(char *msg)         // single program exit point;
 {
@@ -101,6 +102,8 @@
 
     #define log(s) puts("init: " s)
     log("sdl");
+
+    ::chdir(DATADIR);
     
     for(int i = 1; i<argc; i++)
     {
