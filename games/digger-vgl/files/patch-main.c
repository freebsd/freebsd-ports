
$FreeBSD$

--- main.c.orig
+++ main.c
@@ -561,7 +561,6 @@
 {
   int i;
   if (pausef) {
-    pausef=FALSE;
     soundpause();
     sett2val(40);
     setsoundt2();
@@ -575,6 +574,7 @@
     drawlives();
     if (!synchvid)
       curtime=gethrt();
+    pausef=FALSE;
   }
   else
     soundpauseoff();
