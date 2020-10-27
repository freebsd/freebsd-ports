--- src/VBox/Additions/common/crOpenGL/glx_c_exports.c.orig	2020-10-25 11:52:00 UTC
+++ src/VBox/Additions/common/crOpenGL/glx_c_exports.c
@@ -213,8 +213,8 @@ DECLEXPORT(GLXPbufferSGIX) VBOXGLXENTRYTAG(glXCreateGL
     return glxim.CreateGLXPbufferSGIX(dpy, config, width, height, attrib_list);
 }
 
-DECLEXPORT(int) VBOXGLXENTRYTAG(glXQueryGLXPbufferSGIX)
-(Display *dpy, GLXPbuffer pbuf, int attribute, unsigned int *value)
+DECLEXPORT(void) VBOXGLXENTRYTAG(glXQueryGLXPbufferSGIX)
+(Display *dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int *value)
 {
     return glxim.QueryGLXPbufferSGIX(dpy, pbuf, attribute, value);
 }
@@ -225,7 +225,7 @@ DECLEXPORT(GLXFBConfigSGIX *) VBOXGLXENTRYTAG(glXChoos
     return glxim.ChooseFBConfigSGIX(dpy, screen, attrib_list, nelements);
 }
 
-DECLEXPORT(void) VBOXGLXENTRYTAG(glXDestroyGLXPbufferSGIX)(Display *dpy, GLXPbuffer pbuf)
+DECLEXPORT(void) VBOXGLXENTRYTAG(glXDestroyGLXPbufferSGIX)(Display *dpy, GLXPbufferSGIX pbuf)
 {
     return glxim.DestroyGLXPbufferSGIX(dpy, pbuf);
 }
@@ -245,23 +245,23 @@ DECLEXPORT(GLXFBConfigSGIX) VBOXGLXENTRYTAG(glXGetFBCo
     return glxim.GetFBConfigFromVisualSGIX(dpy, vis);
 }
 
-DECLEXPORT(XVisualInfo *) VBOXGLXENTRYTAG(glXGetVisualFromFBConfigSGIX)(Display *dpy, GLXFBConfig config)
+DECLEXPORT(XVisualInfo *) VBOXGLXENTRYTAG(glXGetVisualFromFBConfigSGIX)(Display *dpy, GLXFBConfigSGIX config)
 {
     return glxim.GetVisualFromFBConfigSGIX(dpy, config);
 }
 
 DECLEXPORT(GLXContext) VBOXGLXENTRYTAG(glXCreateContextWithConfigSGIX)
-(Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct)
+(Display *dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct)
 {
     return glxim.CreateContextWithConfigSGIX(dpy, config, render_type, share_list, direct);
 }
 
-DECLEXPORT(GLXPixmap) VBOXGLXENTRYTAG(glXCreateGLXPixmapWithConfigSGIX)(Display *dpy, GLXFBConfig config, Pixmap pixmap)
+DECLEXPORT(GLXPixmap) VBOXGLXENTRYTAG(glXCreateGLXPixmapWithConfigSGIX)(Display *dpy, GLXFBConfigSGIX config, Pixmap pixmap)
 {
     return glxim.CreateGLXPixmapWithConfigSGIX(dpy, config, pixmap);
 }
 
-DECLEXPORT(int) VBOXGLXENTRYTAG(glXGetFBConfigAttribSGIX)(Display *dpy, GLXFBConfig config, int attribute, int *value)
+DECLEXPORT(int) VBOXGLXENTRYTAG(glXGetFBConfigAttribSGIX)(Display *dpy, GLXFBConfigSGIX config, int attribute, int *value)
 {
     return glxim.GetFBConfigAttribSGIX(dpy, config, attribute, value);
 }
