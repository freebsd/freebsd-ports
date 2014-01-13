--- jfsw_src_20051009/source/game.c.orig.orig	2005-10-09 15:28:24.000000000 +0000
+++ jfsw_src_20051009/source/game.c	2010-03-17 07:30:51.119214522 +0000
@@ -197,7 +197,7 @@
 TRUE, // fx on
 TRUE, // Music on
 TRUE, // talking
-TRUE, // ambient
+FALSE, // ambient
 FALSE, // Flip Stereo
 
 // Network game settings
@@ -5182,7 +5182,10 @@
             angvel = info.dyaw >> 8;
         }
     
-    svel -= info.dx;
+    if (!running) svel -= (info.dx / 8.75);
+    else svel -= (info.dx / 4.375);
+    if (!running) vel -= (info.dpitch / 8.75);
+    else vel -= (info.dpitch / 4.375);
 
     switch (ControllerType)
         {
