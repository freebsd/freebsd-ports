--- src/VBox/Additions/common/crOpenGL/fakedri_drv.h.orig	2020-07-09 16:50:09 UTC
+++ src/VBox/Additions/common/crOpenGL/fakedri_drv.h
@@ -80,16 +80,16 @@ extern Bool VBOXGLXENTRYTAG(glXQueryVersion)(Display *
 extern XVisualInfo * VBOXGLXENTRYTAG(glXChooseVisual)(Display *dpy, int screen, int *attribList) ;
 extern const char * VBOXGLXENTRYTAG(glXQueryExtensionsString)(Display *dpy, int screen) ;
 extern GLXPbufferSGIX VBOXGLXENTRYTAG(glXCreateGLXPbufferSGIX)(Display *dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int *attrib_list);
-extern int VBOXGLXENTRYTAG(glXQueryGLXPbufferSGIX)(Display *dpy, GLXPbuffer pbuf, int attribute, unsigned int *value);
+extern void VBOXGLXENTRYTAG(glXQueryGLXPbufferSGIX)(Display *dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int *value);
 extern GLXFBConfigSGIX * VBOXGLXENTRYTAG(glXChooseFBConfigSGIX)(Display *dpy, int screen, int *attrib_list, int *nelements);
-extern void VBOXGLXENTRYTAG(glXDestroyGLXPbufferSGIX)(Display *dpy, GLXPbuffer pbuf) ;
+extern void VBOXGLXENTRYTAG(glXDestroyGLXPbufferSGIX)(Display *dpy, GLXPbufferSGIX pbuf) ;
 extern void VBOXGLXENTRYTAG(glXSelectEventSGIX)(Display *dpy, GLXDrawable drawable, unsigned long mask) ;
 extern void VBOXGLXENTRYTAG(glXGetSelectedEventSGIX)(Display *dpy, GLXDrawable drawable, unsigned long *mask) ;
 extern GLXFBConfigSGIX VBOXGLXENTRYTAG(glXGetFBConfigFromVisualSGIX)(Display *dpy, XVisualInfo *vis) ;
-extern XVisualInfo * VBOXGLXENTRYTAG(glXGetVisualFromFBConfigSGIX)(Display *dpy, GLXFBConfig config) ;
-extern GLXContext VBOXGLXENTRYTAG(glXCreateContextWithConfigSGIX)(Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
-extern GLXPixmap VBOXGLXENTRYTAG(glXCreateGLXPixmapWithConfigSGIX)(Display *dpy, GLXFBConfig config, Pixmap pixmap) ;
-extern int VBOXGLXENTRYTAG(glXGetFBConfigAttribSGIX)(Display *dpy, GLXFBConfig config, int attribute, int *value) ;
+extern XVisualInfo * VBOXGLXENTRYTAG(glXGetVisualFromFBConfigSGIX)(Display *dpy, GLXFBConfigSGIX config) ;
+extern GLXContext VBOXGLXENTRYTAG(glXCreateContextWithConfigSGIX)(Display *dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
+extern GLXPixmap VBOXGLXENTRYTAG(glXCreateGLXPixmapWithConfigSGIX)(Display *dpy, GLXFBConfigSGIX config, Pixmap pixmap) ;
+extern int VBOXGLXENTRYTAG(glXGetFBConfigAttribSGIX)(Display *dpy, GLXFBConfigSGIX config, int attribute, int *value) ;
 extern GLXFBConfig * VBOXGLXENTRYTAG(glXChooseFBConfig)(Display *dpy, int screen, ATTRIB_TYPE *attrib_list, int *nelements) ;
 extern GLXPbuffer VBOXGLXENTRYTAG(glXCreatePbuffer)(Display *dpy, GLXFBConfig config, ATTRIB_TYPE *attrib_list) ;
 extern GLXPixmap VBOXGLXENTRYTAG(glXCreatePixmap)(Display *dpy, GLXFBConfig config, Pixmap pixmap, const ATTRIB_TYPE *attrib_list) ;
