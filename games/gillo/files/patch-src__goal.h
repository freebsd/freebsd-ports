--- src/goal.h.orig
+++ src/goal.h
@@ -32,7 +32,7 @@
 */
 class Goal : public Entity
 {
-	static const float areaRadius = ODE_GOAL_DISTANCE;
+	static const float areaRadius;
 	dGeomID		gids[6];
 public:
     Goal(Context& c);
