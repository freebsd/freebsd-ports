--- src/VBox/Additions/common/crOpenGL/dri_glx.h.orig	2020-07-09 16:50:09 UTC
+++ src/VBox/Additions/common/crOpenGL/dri_glx.h
@@ -111,23 +111,23 @@ extern DECLEXPORT(const char *) VBOXGLXTAG(glXQueryExt
 extern DECLEXPORT(GLXPbufferSGIX) VBOXGLXTAG(glXCreateGLXPbufferSGIX)
 (Display *dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int *attrib_list);
 
-extern DECLEXPORT(int) VBOXGLXTAG(glXQueryGLXPbufferSGIX)
-(Display *dpy, GLXPbuffer pbuf, int attribute, unsigned int *value);
+extern DECLEXPORT(void) VBOXGLXTAG(glXQueryGLXPbufferSGIX)
+(Display *dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int *value);
 
 extern DECLEXPORT(GLXFBConfigSGIX *) VBOXGLXTAG(glXChooseFBConfigSGIX)
 (Display *dpy, int screen, int *attrib_list, int *nelements);
 
-extern DECLEXPORT(void) VBOXGLXTAG(glXDestroyGLXPbufferSGIX)(Display *dpy, GLXPbuffer pbuf);
+extern DECLEXPORT(void) VBOXGLXTAG(glXDestroyGLXPbufferSGIX)(Display *dpy, GLXPbufferSGIX pbuf);
 extern DECLEXPORT(void) VBOXGLXTAG(glXSelectEventSGIX)(Display *dpy, GLXDrawable drawable, unsigned long mask);
 extern DECLEXPORT(void) VBOXGLXTAG(glXGetSelectedEventSGIX)(Display *dpy, GLXDrawable drawable, unsigned long *mask);
 
 extern DECLEXPORT(GLXFBConfigSGIX) VBOXGLXTAG(glXGetFBConfigFromVisualSGIX)(Display *dpy, XVisualInfo *vis);
-extern DECLEXPORT(XVisualInfo *) VBOXGLXTAG(glXGetVisualFromFBConfigSGIX)(Display *dpy, GLXFBConfig config);
+extern DECLEXPORT(XVisualInfo *) VBOXGLXTAG(glXGetVisualFromFBConfigSGIX)(Display *dpy, GLXFBConfigSGIX config);
 extern DECLEXPORT(GLXContext) VBOXGLXTAG(glXCreateContextWithConfigSGIX)
-(Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
+(Display *dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
 
-extern DECLEXPORT(GLXPixmap) VBOXGLXTAG(glXCreateGLXPixmapWithConfigSGIX)(Display *dpy, GLXFBConfig config, Pixmap pixmap);
-extern DECLEXPORT(int) VBOXGLXTAG(glXGetFBConfigAttribSGIX)(Display *dpy, GLXFBConfig config, int attribute, int *value);
+extern DECLEXPORT(GLXPixmap) VBOXGLXTAG(glXCreateGLXPixmapWithConfigSGIX)(Display *dpy, GLXFBConfigSGIX config, Pixmap pixmap);
+extern DECLEXPORT(int) VBOXGLXTAG(glXGetFBConfigAttribSGIX)(Display *dpy, GLXFBConfigSGIX config, int attribute, int *value);
 
 /*
  * GLX 1.3 functions
