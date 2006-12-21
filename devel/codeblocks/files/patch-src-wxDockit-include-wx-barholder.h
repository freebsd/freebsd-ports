--- src/wxDockit/include/wx/barholder.h.orig	Thu Dec 21 00:14:59 2006
+++ src/wxDockit/include/wx/barholder.h	Thu Dec 21 00:15:51 2006
@@ -39,7 +39,7 @@
     }
 
     // Normal constructor
-    wxBarHolder::wxBarHolder( wxWindow *parent, wxWindowID id = -1, const wxPoint& pos = wxDefaultPosition,
+    wxBarHolder( wxWindow *parent, wxWindowID id = -1, const wxPoint& pos = wxDefaultPosition,
         const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxT("barholder") ) {
         Init();
 
