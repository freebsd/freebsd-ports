--- ui/gl/gl_bindings_autogen_glx.h.orig	2019-12-12 12:41:33 UTC
+++ ui/gl/gl_bindings_autogen_glx.h
@@ -104,6 +104,8 @@ typedef bool(GL_BINDING_CALL* glXGetMscRateOMLProc)(Di
                                                     GLXDrawable drawable,
                                                     int32_t* numerator,
                                                     int32_t* denominator);
+typedef __GLXextFuncPtr(GL_BINDING_CALL* glXGetProcAddressARBProc)(
+    const GLubyte* procName);
 typedef void(GL_BINDING_CALL* glXGetSelectedEventProc)(Display* dpy,
                                                        GLXDrawable drawable,
                                                        unsigned long* mask);
@@ -166,6 +168,7 @@ typedef void(GL_BINDING_CALL* glXWaitXProc)(void);
 
 struct ExtensionsGLX {
   bool b_GLX_ARB_create_context;
+  bool b_GLX_ARB_get_proc_address;
   bool b_GLX_EXT_swap_control;
   bool b_GLX_EXT_texture_from_pixmap;
   bool b_GLX_MESA_copy_sub_buffer;
@@ -203,6 +206,7 @@ struct ProcsGLX {
   glXGetFBConfigFromVisualSGIXProc glXGetFBConfigFromVisualSGIXFn;
   glXGetFBConfigsProc glXGetFBConfigsFn;
   glXGetMscRateOMLProc glXGetMscRateOMLFn;
+  glXGetProcAddressARBProc glXGetProcAddressARBFn;
   glXGetSelectedEventProc glXGetSelectedEventFn;
   glXGetSyncValuesOMLProc glXGetSyncValuesOMLFn;
   glXGetVisualFromFBConfigProc glXGetVisualFromFBConfigFn;
@@ -310,6 +314,7 @@ class GL_EXPORT GLXApi {
                                   GLXDrawable drawable,
                                   int32_t* numerator,
                                   int32_t* denominator) = 0;
+  virtual __GLXextFuncPtr glXGetProcAddressARBFn(const GLubyte* procName) = 0;
   virtual void glXGetSelectedEventFn(Display* dpy,
                                      GLXDrawable drawable,
                                      unsigned long* mask) = 0;
@@ -394,6 +399,7 @@ class GL_EXPORT GLXApi {
   ::gl::g_current_glx_context->glXGetFBConfigFromVisualSGIXFn
 #define glXGetFBConfigs ::gl::g_current_glx_context->glXGetFBConfigsFn
 #define glXGetMscRateOML ::gl::g_current_glx_context->glXGetMscRateOMLFn
+#define glXGetProcAddressARB ::gl::g_current_glx_context->glXGetProcAddressARBFn
 #define glXGetSelectedEvent ::gl::g_current_glx_context->glXGetSelectedEventFn
 #define glXGetSyncValuesOML ::gl::g_current_glx_context->glXGetSyncValuesOMLFn
 #define glXGetVisualFromFBConfig \
