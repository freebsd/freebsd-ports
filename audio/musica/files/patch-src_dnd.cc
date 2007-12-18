--- src/dnd.cc.orig	2007-12-18 19:45:04.000000000 +0100
+++ src/dnd.cc	2007-12-18 19:45:56.000000000 +0100
@@ -221,7 +221,7 @@
 
 static void makeDropStyles(void)
 {
-  GdkColor color;
+  GdkColor color = { 0,0,0,0 };
   int i;
 
   if(eventBoxDefaultStyle == 0)
