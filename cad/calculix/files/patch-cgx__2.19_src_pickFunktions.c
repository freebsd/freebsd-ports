--- cgx_2.19/src/pickFunktions.c.orig	2021-09-18 09:40:04 UTC
+++ cgx_2.19/src/pickFunktions.c
@@ -4594,7 +4594,7 @@ void moveLineEndPoint(int lineNr, int pntNr, double ll
     else
     {
       printf("ERROR: selected point:%s is no line endpoint\n", point[pntNr].name);
-      return(-1);
+      return;
     }
     u=flag*llength;
     u/=scale->w;
