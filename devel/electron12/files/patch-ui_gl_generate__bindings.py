--- ui/gl/generate_bindings.py.orig	2021-04-14 01:09:39 UTC
+++ ui/gl/generate_bindings.py
@@ -2840,6 +2840,9 @@ GLX_FUNCTIONS = [
   'arguments':
       'Display* dpy, GLXDrawable drawable, int32_t* numerator, '
       'int32_t* denominator' },
+{ 'return_type': '__GLXextFuncPtr',
+  'names': ['glXGetProcAddressARB'],
+  'arguments': 'const GLubyte* procName', },
 { 'return_type': 'void',
   'names': ['glXGetSelectedEvent'],
   'arguments': 'Display* dpy, GLXDrawable drawable, unsigned long* mask', },
