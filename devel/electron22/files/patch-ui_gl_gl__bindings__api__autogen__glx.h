--- ui/gl/gl_bindings_api_autogen_glx.h.orig	2021-04-14 18:41:39 UTC
+++ ui/gl/gl_bindings_api_autogen_glx.h
@@ -88,6 +88,7 @@ bool glXGetMscRateOMLFn(Display* dpy,
                         GLXDrawable drawable,
                         int32_t* numerator,
                         int32_t* denominator) override;
+__GLXextFuncPtr glXGetProcAddressARBFn(const GLubyte* procName) override;
 void glXGetSelectedEventFn(Display* dpy,
                            GLXDrawable drawable,
                            unsigned long* mask) override;
