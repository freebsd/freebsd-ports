--- newlisp.h.orig
+++ newlisp.h
@@ -36,6 +36,10 @@
 #  include <ffi.h>
 #endif
 
+#ifdef __FreeBSD__
+#  include <ffi.h>
+#endif
+
 #define LIBFFI " libffi"
 #else /* not FFI */
 #define LIBFFI ""
