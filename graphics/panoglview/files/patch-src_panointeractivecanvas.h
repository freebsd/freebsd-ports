--- src/panointeractivecanvas.h.orig	2008-07-23 21:09:11 UTC
+++ src/panointeractivecanvas.h
@@ -39,7 +39,11 @@ class panoInteractiveCanvas : public panoCanvas (publi
   void OnMouse(wxMouseEvent& event);
   void OnTimer(wxTimerEvent &event);
   void OnPaint(wxPaintEvent &event);
+#if wxCHECK_VERSION(3,0,0)
+  void resized(wxSizeEvent &event);
+#else //wxCHECK_VERSION(3,0,0)
   void OnSize(wxSizeEvent &event);
+#endif //wxCHECK_VERSION(3,0,0)
   void setBoundaryMode(int boundarymode);
   void enableShowBoundaries(bool show);
   void enableUseBoundaries(bool use);
