--- src/simpleball.cpp.orig
+++ src/simpleball.cpp
@@ -26,6 +26,8 @@
 const sgVec4 SimpleBall::p1[3] = { {0.3, 0.0, 0.0, 1.0}, {1.0, 0.0, 0.0, 1.0}, {1.0, 0.4, 0.4, 1.0} };
 const sgVec4 SimpleBall::ne[3] = { {0.0, 0.0, 0.0, 1}, {0.6, 0.6, 0.6, 1}, {1.0, 1.0, 1.0, 1} };
 const sgVec4 SimpleBall::p2[3] = { {0.0, 0.0, 0.3, 1}, {0.0, 0.0, 1.0, 1}, {0.4, 0.4, 1.0, 1} };
+const double SimpleBall::weight = ODE_BALL_MASS;
+const double SimpleBall::radius = ODE_BALL_RADIUS;
 
 SimpleBall::SimpleBall(Context& c)
 : Entity(c), ballEffectPtr(NULL), possessionIncrement(0), targetSize(2*radius), currentSize(2*radius)
