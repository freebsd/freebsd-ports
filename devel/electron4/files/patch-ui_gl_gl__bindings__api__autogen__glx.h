--- ui/gl/gl_bindings_api_autogen_glx.h.orig	2019-03-15 06:38:28 UTC
+++ ui/gl/gl_bindings_api_autogen_glx.h
@@ -84,6 +84,7 @@ bool glXGetMscRateOMLFn(Display* dpy,
                         GLXDrawable drawable,
                         int32_t* numerator,
                         int32_t* denominator) override;
+__GLXextFuncPtr glXGetProcAddressARBFn(const GLubyte* procName) override;
 void glXGetSelectedEventFn(Display* dpy,
                            GLXDrawable drawable,
                            unsigned long* mask) override;
