--- src/goal.cpp.orig
+++ src/goal.cpp
@@ -22,6 +22,8 @@
 
 namespace gillo {
 
+const float Goal::areaRadius = ODE_GOAL_DISTANCE;
+
 Goal::Goal(Context& c)
  : Entity(c)
 {
