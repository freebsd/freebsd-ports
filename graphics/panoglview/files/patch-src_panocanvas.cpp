--- src/panocanvas.cpp.orig	2008-07-23 21:09:12 UTC
+++ src/panocanvas.cpp
@@ -41,12 +41,20 @@
     
 BEGIN_EVENT_TABLE(panoCanvas, wxGLCanvas)
   EVT_PAINT(panoCanvas::OnPaint)
+#if wxCHECK_VERSION(3,0,0)
+  EVT_SIZE (panoCanvas::resized)
+#else //wxCHECK_VERSION(3,0,0)
   EVT_SIZE (panoCanvas::OnSize)
+#endif //wxCHECK_VERSION(3,0,0)
   EVT_ERASE_BACKGROUND(panoCanvas::OnEraseBackground)
 END_EVENT_TABLE()
 
 panoCanvas::panoCanvas(wxWindow *parent, int id, const wxPoint &position, const wxSize &size) :
+#if wxCHECK_VERSION(3,0,0)
+wxGLCanvas(parent,id,0,position,size),
+#else //wxCHECK_VERSION(3,0,0)
 wxGLCanvas(parent,id,position,size),
+#endif //wxCHECK_VERSION(3,0,0)
 m_position(0.0,0.0,50.0),
 m_aspectratio(size.GetWidth()/(double) size.GetHeight()),
 m_initialized(false),
@@ -56,6 +64,9 @@ m_currentboundaries(CPanRange  (-m_position.getFov()*m
                     CAngleRange( -m_position.getFov()              / 2.0, m_position.getFov()               / 2.0),
                     CAngleRange(                       0.0,                     180.0 )),
 m_imageboundaries(CPanRange(-180.0,180.0),CAngleRange(-90.0,90.0),CAngleRange(0.0,180.0)),
+#if wxCHECK_VERSION(3,0,0)
+m_context(new wxGLContext(this)),
+#endif //wxCHECK_VERSION(3,0,0)
 m_divisions(128)
 {
   for(int i=0;i<16;++i)
@@ -68,24 +79,40 @@ panoCanvas::~panoCanvas()
 {
   if(m_hasimage)
     deletePanorama();
+#if wxCHECK_VERSION(3,0,0)
+  delete m_context;
+#endif //wxCHECK_VERSION(3,0,0)
 }
 
 void panoCanvas::OnEraseBackground(wxEraseEvent& event)
 {
 }
 
+#if wxCHECK_VERSION(3,0,0)
+void panoCanvas::resized(wxSizeEvent &event)
+#else //wxCHECK_VERSION(3,0,0)
 void panoCanvas::OnSize(wxSizeEvent &event)
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
 
 
   glViewport(0,0,(GLint) w, (GLint) h);
   m_aspectratio = (GLdouble) w/(GLdouble) h;
   m_winsize = wxSize(w,h);
+#if wxCHECK_VERSION(3,0,0)
+  Refresh();
+#endif //wxCHECK_VERSION(3,0,0)
 }
 
 void panoCanvas::OnPaint(wxPaintEvent &event)
@@ -93,7 +120,11 @@ void panoCanvas::OnPaint(wxPaintEvent &event)
   /* must always be here */
   wxPaintDC dc(this);
 
+#if wxCHECK_VERSION(3,0,0)
+  SetCurrent(*m_context);
+#else //wxCHECK_VERSION(3,0,0)
   SetCurrent();
+#endif //wxCHECK_VERSION(3,0,0)
 
   if(!m_initialized){
     initGL();
@@ -125,7 +156,11 @@ void panoCanvas::position()
 
 void panoCanvas::deletePanorama()
 {
+#if wxCHECK_VERSION(3,0,0)
+  SetCurrent(*m_context);
+#else //wxCHECK_VERSION(3,0,0)
   SetCurrent();
+#endif //wxCHECK_VERSION(3,0,0)
   glDeleteTextures(m_numOfTexPatches.x*m_numOfTexPatches.y,m_textures);
   m_hasimage = false;
   delete [] m_viewableTexPatches;
