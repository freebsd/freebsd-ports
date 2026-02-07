--- include/agg_renderer_outline_aa.h.orig	2023-08-21 15:51:12 UTC
+++ include/agg_renderer_outline_aa.h
@@ -1366,7 +1366,7 @@ namespace agg
         //---------------------------------------------------------------------
         void profile(line_profile_aa& prof) { m_profile = &prof; }
         const line_profile_aa& profile() const { return *m_profile; }
-        line_profile_aa& profile() { return *m_profile; }
+        const line_profile_aa& profile() { return *m_profile; }
 
         //---------------------------------------------------------------------
         int subpixel_width() const { return m_profile->subpixel_width(); }
