--- libopenage/pathfinding/pathfinder.cpp.orig	2024-12-08 11:19:50 UTC
+++ libopenage/pathfinding/pathfinder.cpp
@@ -470,7 +470,7 @@ PortalNode::PortalNode(const std::shared_ptr<Portal> &
 
 PortalNode::PortalNode(const std::shared_ptr<Portal> &portal) :
 	portal{portal},
-	entry_sector{NULL},
+	entry_sector{0},
 	future_cost{std::numeric_limits<int>::max()},
 	current_cost{std::numeric_limits<int>::max()},
 	heuristic_cost{std::numeric_limits<int>::max()},
