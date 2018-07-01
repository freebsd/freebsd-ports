--- ufraw_developer.c.orig	2018-06-23 21:40:09 UTC
+++ ufraw_developer.c
@@ -387,7 +387,7 @@ static double findExpCoeff(double b)
     else a = b;
     bg = a / (1 - exp(-a));
     /* The limit on try is just to be sure there is no infinite loop. */
-    for (try = 0; abs(bg - b) > 0.001 || try < 100; try++) {
+    for (try = 0; fabs(bg - b) > 0.001 || try < 100; try++) {
                     a = a + (b - bg);
                     bg = a / (1 - exp(-a));
                 }
