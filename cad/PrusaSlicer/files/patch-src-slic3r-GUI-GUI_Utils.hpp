--- src/slic3r/GUI/GUI_Utils.hpp.orig	2019-12-10 15:09:10 UTC
+++ src/slic3r/GUI/GUI_Utils.hpp
@@ -50,7 +50,7 @@ struct DpiChangedEvent : public wxEvent {
     }
 };
 
-wxDECLARE_EVENT(EVT_DPI_CHANGED, DpiChangedEvent);
+wxDECLARE_EVENT(psEVT_DPI_CHANGED, DpiChangedEvent);
 
 template<class P> class DPIAware : public P
 {
@@ -75,7 +75,7 @@ template<class P> class DPIAware : public P (public)
 
 //        recalc_font();
 
-        this->Bind(EVT_DPI_CHANGED, [this](const DpiChangedEvent &evt) {
+        this->Bind(psEVT_DPI_CHANGED, [this](const DpiChangedEvent &evt) {
             m_scale_factor = (float)evt.dpi / (float)DPI_DEFAULT;
 
             m_new_font_point_size = get_default_font_for_dpi(evt.dpi).GetPointSize();
