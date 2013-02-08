--- src/d_iwad.c	2011-05-17 16:01:48.000000000 -0700
+++ src/d_iwad.c	2011-10-15 11:30:26.998495197 -0700
@@ -559,8 +559,7 @@
 
     // Standard places where IWAD files are installed under Unix.
 
-    AddIWADDir("/usr/share/games/doom");
-    AddIWADDir("/usr/local/share/games/doom");
+    AddIWADDir("/usr/local/share/doom");
 
 #endif
 
