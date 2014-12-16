--- trek/computer.c.orig	2014-12-12 15:10:37 UTC
+++ trek/computer.c
@@ -175,10 +175,10 @@ computer(int v __unused)
 				tqy = Ship.quady;
 			} else {
 				ix = getintpar("Quadrant");
-				if (ix < 0 || ix >= NSECTS)
+				if (ix < 0 || ix >= NQUADS)
 					break;
 				iy = getintpar("q-y");
-				if (iy < 0 || iy >= NSECTS)
+				if (iy < 0 || iy >= NQUADS)
 					break;
 				tqx = ix;
 				tqy = iy;
