--- src/asteroid.cc.orig	Sat Jan 17 17:27:37 2004
+++ src/asteroid.cc	Sat Jan 17 17:27:56 2004
@@ -84,8 +84,8 @@
 
 	mp = (p0 + p1) / 2;
 
-	float r = (distance(p0, bc) + distance(p1, bc)) / 2; // radius
-	float l = distance(p0, p1); // edge length
+	float r = (dist(p0, bc) + dist(p1, bc)) / 2; // radius
+	float l = dist(p0, p1); // edge length
 	l *= strength;
 	srand48(seed + p0.hash() + p1.hash());
 	float d = drand48() - 0.5;
