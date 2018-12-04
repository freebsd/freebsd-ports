--- src/panointeractivecanvas.cpp.orig	2008-07-23 21:09:12 UTC
+++ src/panointeractivecanvas.cpp
@@ -62,7 +62,11 @@ BEGIN_EVENT_TABLE(panoInteractiveCanvas, panoCanvas)
   EVT_KEY_DOWN    (panoInteractiveCanvas::OnKeyDown       )
   EVT_KEY_UP      (panoInteractiveCanvas::OnKeyUp         )
   EVT_PAINT       (panoInteractiveCanvas::OnPaint         )
+#if wxCHECK_VERSION(3,0,0)
+  EVT_SIZE        (panoInteractiveCanvas::resized         )
+#else //wxCHECK_VERSION(3,0,0)
   EVT_SIZE        (panoInteractiveCanvas::OnSize          )
+#endif //wxCHECK_VERSION(3,0,0)
 END_EVENT_TABLE()
 
 panoInteractiveCanvas::panoInteractiveCanvas(wxWindow* parent, int id, const wxPoint& position, const wxSize& size):
@@ -96,13 +100,23 @@ panoInteractiveCanvas::~panoInteractiveCanvas()
 {
 }
 
+#if wxCHECK_VERSION(3,0,0)
+void panoInteractiveCanvas::resized(wxSizeEvent &event)
+#else //wxCHECK_VERSION(3,0,0)
 void panoInteractiveCanvas::OnSize(wxSizeEvent &event)
+#endif //wxCHECK_VERSION(3,0,0)
 {
+#if !wxCHECK_VERSION(3,0,0)
   wxGLCanvas::OnSize(event);
+#endif //!wxCHECK_VERSION(3,0,0)
 
   int w,h;
   GetClientSize(&w,&h);
+#if wxCHECK_VERSION(3,0,0)
+  if (GetXWindow()) SetCurrent(*m_context);
+#else //wxCHECK_VERSION(3,0,0)
   SetCurrent();
+#endif //wxCHECK_VERSION(3,0,0)
 
   // TODO: opengl needs to be initialized here.
   if(m_initialized){
@@ -121,6 +135,9 @@ void panoInteractiveCanvas::OnSize(wxSizeEvent &event)
 
   m_aspectratio = (GLdouble) w/(GLdouble) h;
   m_winsize = wxSize(w,h);
+#if wxCHECK_VERSION(3,0,0)
+  Refresh();
+#endif //wxCHECK_VERSION(3,0,0)
 }
 
 void panoInteractiveCanvas::OnPaint(wxPaintEvent &event)
@@ -128,7 +145,11 @@ void panoInteractiveCanvas::OnPaint(wxPaintEvent &even
   /* must always be here */
   wxPaintDC dc(this);
 
+#if wxCHECK_VERSION(3,0,0)
+  SetCurrent(*m_context);
+#else //wxCHECK_VERSION(3,0,0)
   SetCurrent();
+#endif //wxCHECK_VERSION(3,0,0)
 
   if(!m_initialized){
     initGL();
