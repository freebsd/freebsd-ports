--- src/simpleball.h.orig
+++ src/simpleball.h
@@ -37,8 +37,8 @@
 	static const sgVec4 p1[3];
 	static const sgVec4 ne[3];
 	static const sgVec4 p2[3];
-	static const double weight = ODE_BALL_MASS;
-	static const double radius = ODE_BALL_RADIUS;
+	static const double weight;
+	static const double radius;
     
 	SimpleBall(Context& c);
 	SimpleBall(Context& c, float size, ssgSimpleState* state);
