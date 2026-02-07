--- src/panocanvas.h.orig	2008-07-23 21:09:11 UTC
+++ src/panocanvas.h
@@ -148,7 +148,11 @@ class panoCanvas : public wxGLCanvas  { (public)
   panoCanvas(wxWindow *parent, int id, const wxPoint &position=wxDefaultPosition, const wxSize &size=wxDefaultSize);
   virtual ~panoCanvas();
   void OnPaint(wxPaintEvent &event);
+#if wxCHECK_VERSION(3,0,0)
+  void resized(wxSizeEvent &event);
+#else //wxCHECK_VERSION(3,0,0)
   void OnSize(wxSizeEvent &event);
+#endif //wxCHECK_VERSION(3,0,0)
   void OnEraseBackground(wxEraseEvent& event);
 
   CBoundaries calculateViewBoundaries(const CPosition &offset = CPosition());
@@ -198,6 +202,9 @@ class panoCanvas : public wxGLCanvas  { (public)
   CBoundaries m_currentboundaries;
   CBoundaries m_imageboundaries;
   bool     m_initialized;
+#if wxCHECK_VERSION(3,0,0)
+  wxGLContext *m_context;
+#endif //wxCHECK_VERSION(3,0,0)
   DECLARE_EVENT_TABLE();
 };
 
