--- ui/gl/gl_bindings_autogen_glx.cc.orig	2019-09-10 10:43:23 UTC
+++ ui/gl/gl_bindings_autogen_glx.cc
@@ -115,6 +115,8 @@ void DriverGLX::InitializeExtensionBindings() {
 
   ext.b_GLX_ARB_create_context =
       gfx::HasExtension(extensions, "GLX_ARB_create_context");
+  ext.b_GLX_ARB_get_proc_address =
+      gfx::HasExtension(extensions, "GLX_ARB_get_proc_address");
   ext.b_GLX_EXT_swap_control =
       gfx::HasExtension(extensions, "GLX_EXT_swap_control");
   ext.b_GLX_EXT_texture_from_pixmap =
@@ -145,6 +147,11 @@ void DriverGLX::InitializeExtensionBindings() {
             GetGLProcAddress("glXCreateContextAttribsARB"));
   }
 
+  if (ext.b_GLX_ARB_get_proc_address) {
+    fn.glXGetProcAddressARBFn = reinterpret_cast<glXGetProcAddressARBProc>(
+        GetGLProcAddress("glXGetProcAddressARB"));
+  }
+
   if (ext.b_GLX_SGIX_fbconfig) {
     fn.glXGetFBConfigFromVisualSGIXFn =
         reinterpret_cast<glXGetFBConfigFromVisualSGIXProc>(
@@ -346,6 +353,10 @@ bool GLXApiBase::glXGetMscRateOMLFn(Display* dpy,
   return driver_->fn.glXGetMscRateOMLFn(dpy, drawable, numerator, denominator);
 }
 
+__GLXextFuncPtr GLXApiBase::glXGetProcAddressARBFn(const GLubyte* procName) {
+  return driver_->fn.glXGetProcAddressARBFn(procName);
+}
+
 void GLXApiBase::glXGetSelectedEventFn(Display* dpy,
                                        GLXDrawable drawable,
                                        unsigned long* mask) {
@@ -646,6 +657,11 @@ bool TraceGLXApi::glXGetMscRateOMLFn(Display* dpy,
   return glx_api_->glXGetMscRateOMLFn(dpy, drawable, numerator, denominator);
 }
 
+__GLXextFuncPtr TraceGLXApi::glXGetProcAddressARBFn(const GLubyte* procName) {
+  TRACE_EVENT_BINARY_EFFICIENT0("gpu", "TraceGLAPI::glXGetProcAddressARB")
+  return glx_api_->glXGetProcAddressARBFn(procName);
+}
+
 void TraceGLXApi::glXGetSelectedEventFn(Display* dpy,
                                         GLXDrawable drawable,
                                         unsigned long* mask) {
@@ -1068,6 +1084,14 @@ bool DebugGLXApi::glXGetMscRateOMLFn(Display* dpy,
                  << static_cast<const void*>(denominator) << ")");
   bool result =
       glx_api_->glXGetMscRateOMLFn(dpy, drawable, numerator, denominator);
+  GL_SERVICE_LOG("GL_RESULT: " << result);
+  return result;
+}
+
+__GLXextFuncPtr DebugGLXApi::glXGetProcAddressARBFn(const GLubyte* procName) {
+  GL_SERVICE_LOG("glXGetProcAddressARB"
+                 << "(" << static_cast<const void*>(procName) << ")");
+  __GLXextFuncPtr result = glx_api_->glXGetProcAddressARBFn(procName);
   GL_SERVICE_LOG("GL_RESULT: " << result);
   return result;
 }
