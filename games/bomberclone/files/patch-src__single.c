--- ./src/single.c.orig	2006-08-20 01:41:47.000000000 +0200
+++ ./src/single.c	2014-01-19 02:30:56.000000000 +0100
@@ -476,7 +476,7 @@
 };
 
 
-inline int
+int
 ai_checknewpos (_point pos, int d)
 {
     _point m;
