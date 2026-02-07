--- src/VBox/Additions/common/crOpenGL/glx_proto.h.orig	2020-07-09 16:50:09 UTC
+++ src/VBox/Additions/common/crOpenGL/glx_proto.h
@@ -95,23 +95,23 @@ typedef const char * (*PGLXFUNC_QueryExtensionsString)
 typedef GLXPbufferSGIX (*PGLXFUNC_CreateGLXPbufferSGIX)
 (Display *dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int *attrib_list);
 
-typedef int (*PGLXFUNC_QueryGLXPbufferSGIX)
-(Display *dpy, GLXPbuffer pbuf, int attribute, unsigned int *value);
+typedef void (*PGLXFUNC_QueryGLXPbufferSGIX)
+(Display *dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int *value);
 
 typedef GLXFBConfigSGIX * (*PGLXFUNC_ChooseFBConfigSGIX)
 (Display *dpy, int screen, int *attrib_list, int *nelements);
 
-typedef void (*PGLXFUNC_DestroyGLXPbufferSGIX)(Display *dpy, GLXPbuffer pbuf);
+typedef void (*PGLXFUNC_DestroyGLXPbufferSGIX)(Display *dpy, GLXPbufferSGIX pbuf);
 typedef void (*PGLXFUNC_SelectEventSGIX)(Display *dpy, GLXDrawable drawable, unsigned long mask);
 typedef void (*PGLXFUNC_GetSelectedEventSGIX)(Display *dpy, GLXDrawable drawable, unsigned long *mask);
 
 typedef GLXFBConfigSGIX (*PGLXFUNC_GetFBConfigFromVisualSGIX)(Display *dpy, XVisualInfo *vis);
-typedef XVisualInfo * (*PGLXFUNC_GetVisualFromFBConfigSGIX)(Display *dpy, GLXFBConfig config);
+typedef XVisualInfo * (*PGLXFUNC_GetVisualFromFBConfigSGIX)(Display *dpy, GLXFBConfigSGIX config);
 typedef GLXContext (*PGLXFUNC_CreateContextWithConfigSGIX)
-(Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
+(Display *dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
 
-typedef GLXPixmap (*PGLXFUNC_CreateGLXPixmapWithConfigSGIX)(Display *dpy, GLXFBConfig config, Pixmap pixmap);
-typedef int (*PGLXFUNC_GetFBConfigAttribSGIX)(Display *dpy, GLXFBConfig config, int attribute, int *value);
+typedef GLXPixmap (*PGLXFUNC_CreateGLXPixmapWithConfigSGIX)(Display *dpy, GLXFBConfigSGIX config, Pixmap pixmap);
+typedef int (*PGLXFUNC_GetFBConfigAttribSGIX)(Display *dpy, GLXFBConfigSGIX config, int attribute, int *value);
 
 /*
  * GLX 1.3 functions
