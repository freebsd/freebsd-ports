--- src/single.c.orig	2013-10-12 22:40:49.000000000 +1100
+++ src/single.c	2013-10-12 22:41:09.000000000 +1100
@@ -476,7 +476,7 @@
 };
 
 
-inline int
+int
 ai_checknewpos (_point pos, int d)
 {
     _point m;
