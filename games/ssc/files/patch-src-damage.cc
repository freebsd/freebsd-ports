--- src/damage.cc.orig	Sat Jan 17 17:31:55 2004
+++ src/damage.cc	Sat Jan 17 17:32:04 2004
@@ -44,7 +44,7 @@
 {
 	if (obj.mFlocking)
 	{
-		double d = distance(mPosition, obj.mPosition);
+		double d = dist(mPosition, obj.mPosition);
 		if (d > 0 && d < 50) interact(obj);
 	}
 
