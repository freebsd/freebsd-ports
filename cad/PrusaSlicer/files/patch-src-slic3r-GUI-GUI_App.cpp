--- src/slic3r/GUI/GUI_App.cpp.orig	2019-12-10 15:09:10 UTC
+++ src/slic3r/GUI/GUI_App.cpp
@@ -100,7 +100,7 @@ static void register_dpi_event()
         const auto rect = reinterpret_cast<PRECT>(lParam);
         const wxRect wxrect(wxPoint(rect->top, rect->left), wxPoint(rect->bottom, rect->right));
 
-        DpiChangedEvent evt(EVT_DPI_CHANGED, dpi, wxrect);
+        DpiChangedEvent evt(psEVT_DPI_CHANGED, dpi, wxrect);
         win->GetEventHandler()->AddPendingEvent(evt);
 
         return true;
