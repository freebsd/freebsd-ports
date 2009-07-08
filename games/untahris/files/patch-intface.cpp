--- intface.cpp.orig	2009-05-20 01:41:32.000000000 +0400
+++ intface.cpp	2009-07-07 17:38:01.000000000 +0400
@@ -834,7 +834,7 @@
   Ic(icBazooka).fillWith("0", d.Res);
   Ic(icBazooka).gradFill(d.Res*4/8-1, 0, d.Res*4/8, d.Res*3/4, 0x80FFFFFF, 0xFFFFFFFF);
 
-  char buf[64];
+  char buf[1024];
   sprintf(buf, "graph%d%s.unt", d.Res, gtNames[c.graphicsType]);
   FILE *f = fopen(buf, "rt");
   if(f) {
