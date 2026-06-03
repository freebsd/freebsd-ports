--- src/UCTNode.cpp.orig	2025-08-23 18:43:12 UTC
+++ src/UCTNode.cpp
@@ -361,8 +361,7 @@ UCTNode* UCTNode::uct_select_child(const int color, co
     return best->get();
 }
 
-class NodeComp
-    : public std::binary_function<UCTNodePointer&, UCTNodePointer&, bool> {
+class NodeComp {
 public:
     NodeComp(const int color, const float lcb_min_visits)
         : m_color(color), m_lcb_min_visits(lcb_min_visits) {}
