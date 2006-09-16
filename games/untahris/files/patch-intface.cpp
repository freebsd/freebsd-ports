--- intface.cpp.orig	Mon Sep  4 19:16:15 2006
+++ intface.cpp	Fri Sep  8 06:57:45 2006
@@ -517,7 +517,7 @@
       thruster.pixel[y][x] = 'P';
     }
   
-  char buf[64];
+  char buf[1024];
   sprintf(buf, "graph%d.unt", d.Res);
   FILE *f = fopen(buf, "rt");
   if(f) {
