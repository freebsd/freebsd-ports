Change similar to upstream commit 9cc1926e8126163d3b8877c0112e11c462a96384:
remove unused code to fix build with boost 1.76

--- UI/CombatReport/GraphicalSummary.cpp.orig	2020-09-25 11:06:39 UTC
+++ UI/CombatReport/GraphicalSummary.cpp
@@ -409,6 +409,7 @@ class SideBar : public GG::Wnd { (public)
         m_y_axis_label->MoveTo(GG::Pt(-m_y_axis_label->MinUsableSize().x / 2 - AXIS_WIDTH, Height()/2 - m_y_axis_label->Height()/2));
     }
 
+	/*
     void DrawArrow(GG::Pt begin, GG::Pt end) {
         double head_width = 5.0;
         // A vector (math) of the arrow we wish to draw
@@ -493,6 +494,7 @@ class SideBar : public GG::Wnd { (public)
         DrawArrow(begin, x_end);
         DrawArrow(begin, y_end);
     }
+	*/
 
     void SizeMove(const GG::Pt& ul, const GG::Pt& lr) override {
         GG::Wnd::SizeMove(ul, lr);
