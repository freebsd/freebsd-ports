--- src/colour.cpp.orig	2011-10-30 15:52:53 UTC
+++ src/colour.cpp
@@ -47,9 +47,9 @@ unsigned int obby::colour::get_blue() co
 bool obby::colour::similar_colour(const colour& colour) const
 {
 	// TODO: Convert to HSV for better checking
-	return abs(m_red - colour.m_red) +
-	       abs(m_green - colour.m_green) +
-	       abs(m_blue - colour.m_blue) < 32;
+	return abs((int)(m_red - colour.m_red)) +
+	       abs((int)(m_green - colour.m_green)) +
+	       abs((int)(m_blue - colour.m_blue)) < 32;
 }
 
 std::string serialise::default_context_to<obby::colour>::
