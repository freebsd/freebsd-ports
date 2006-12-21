--- src/main.cpp.orig	Thu Dec 21 00:18:40 2006
+++ src/main.cpp	Thu Dec 21 00:19:06 2006
@@ -65,7 +65,7 @@
 class wxMyFileDropTarget : public wxFileDropTarget
 {
 public:
-    wxMyFileDropTarget::wxMyFileDropTarget(MainFrame *frame):m_frame(frame){}
+    wxMyFileDropTarget(MainFrame *frame):m_frame(frame){}
     virtual bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames)
     {
         if(!m_frame) return false;
