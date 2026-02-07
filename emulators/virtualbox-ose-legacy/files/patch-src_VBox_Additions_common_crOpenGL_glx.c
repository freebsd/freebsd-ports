--- src/VBox/Additions/common/crOpenGL/glx.c.orig	2020-07-09 16:50:09 UTC
+++ src/VBox/Additions/common/crOpenGL/glx.c
@@ -742,7 +742,7 @@ VBOXGLXTAG(glXCreateGLXPbufferSGIX)(Display *dpy, GLXF
     return 0;
 }
 
-DECLEXPORT(void) VBOXGLXTAG(glXDestroyGLXPbufferSGIX)(Display *dpy, GLXPbuffer pbuf)
+DECLEXPORT(void) VBOXGLXTAG(glXDestroyGLXPbufferSGIX)(Display *dpy, GLXPbufferSGIX pbuf)
 {
     (void) dpy;
     (void) pbuf;
@@ -763,7 +763,7 @@ DECLEXPORT(void) VBOXGLXTAG(glXGetSelectedEventSGIX)(D
     (void) mask;
 }
 
-DECLEXPORT(int) VBOXGLXTAG(glXQueryGLXPbufferSGIX)(Display *dpy, GLXPbuffer pbuf,
+DECLEXPORT(void) VBOXGLXTAG(glXQueryGLXPbufferSGIX)(Display *dpy, GLXPbufferSGIX pbuf,
                                                    int attribute, unsigned int *value)
 {
     (void) dpy;
@@ -771,10 +771,9 @@ DECLEXPORT(int) VBOXGLXTAG(glXQueryGLXPbufferSGIX)(Dis
     (void) attribute;
     (void) value;
     crWarning("glXQueryGLXPbufferSGIX not implemented by Chromium");
-    return 0;
 }
 
-DECLEXPORT(int) VBOXGLXTAG(glXGetFBConfigAttribSGIX)(Display *dpy, GLXFBConfig config,
+DECLEXPORT(int) VBOXGLXTAG(glXGetFBConfigAttribSGIX)(Display *dpy, GLXFBConfigSGIX config,
                                                      int attribute, int *value)
 {
     return VBOXGLXTAG(glXGetFBConfigAttrib)(dpy, config, attribute, value);
@@ -789,14 +788,14 @@ VBOXGLXTAG(glXChooseFBConfigSGIX)(Display *dpy, int sc
 
 DECLEXPORT(GLXPixmap)
 VBOXGLXTAG(glXCreateGLXPixmapWithConfigSGIX)(Display *dpy,
-                                             GLXFBConfig config,
+                                             GLXFBConfigSGIX config,
                                              Pixmap pixmap)
 {
     return VBOXGLXTAG(glXCreatePixmap)(dpy, config, pixmap, NULL);
 }
 
 DECLEXPORT(GLXContext)
-VBOXGLXTAG(glXCreateContextWithConfigSGIX)(Display *dpy, GLXFBConfig config,
+VBOXGLXTAG(glXCreateContextWithConfigSGIX)(Display *dpy, GLXFBConfigSGIX config,
                                            int render_type,
                                            GLXContext share_list,
                                            Bool direct)
@@ -812,7 +811,7 @@ VBOXGLXTAG(glXCreateContextWithConfigSGIX)(Display *dp
 
 DECLEXPORT(XVisualInfo *)
 VBOXGLXTAG(glXGetVisualFromFBConfigSGIX)(Display *dpy,
-                                         GLXFBConfig config)
+                                         GLXFBConfigSGIX config)
 {
     return visualInfoFromFBConfig(dpy, config);
 }
