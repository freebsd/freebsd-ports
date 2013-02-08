--- include/agg_renderer_outline_aa.h.orig	2006-10-09 13:07:08.000000000 +0900
+++ include/agg_renderer_outline_aa.h	2012-10-13 05:25:48.000000000 +0900
@@ -1375,7 +1375,7 @@
         //---------------------------------------------------------------------
         void profile(const line_profile_aa& prof) { m_profile = &prof; }
         const line_profile_aa& profile() const { return *m_profile; }
-        line_profile_aa& profile() { return *m_profile; }
+        const line_profile_aa& profile() { return *m_profile; }
 
         //---------------------------------------------------------------------
         int subpixel_width() const { return m_profile->subpixel_width(); }
