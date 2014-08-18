--- src/lib/sced/labeltxt.c.orig	1997-03-21 22:04:16.000000000 +0000
+++ src/lib/sced/labeltxt.c
@@ -175,7 +175,7 @@ int x, y, degrees, scale;
     if (!strcmp(dispdev->name,"wp")) {
         /* use plain text for now */
         DevText(text,x,y);
-        return;
+        return (0);
     }
 
     /* Hack!  If degrees is >= 90, an angle is assumed.
@@ -185,7 +185,7 @@ int x, y, degrees, scale;
 
     if (!strcmp(dispdev->name,"postscript")) {
         PS_ScaledText(text,x,y,degrees);
-        return;
+        return (0);
     }
 
     if (degrees & 1) {
