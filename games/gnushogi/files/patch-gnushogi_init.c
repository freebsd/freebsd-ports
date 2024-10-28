--- gnushogi/init.c.orig	2014-02-17 20:26:59 UTC
+++ gnushogi/init.c
@@ -100,7 +100,7 @@ distance(short a, short b)
 short
 distance(short a, short b)
 {
-    return (use_distdata
+    return (use_distdata && a < NO_SQUARES && b < NO_SQUARES
             ? (short)(*distdata)[(int)a][(int)b]
             : (short)computed_distance(a, b));
 }
