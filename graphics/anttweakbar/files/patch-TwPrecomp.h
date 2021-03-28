- error: "<malloc.h> has been replaced by <stdlib.h>"

--- TwPrecomp.h.orig	2021-03-28 08:35:14 UTC
+++ TwPrecomp.h
@@ -51,7 +51,11 @@
 #   include <GL/glx.h>
 #   include <X11/Xatom.h>
 #   include <unistd.h>
+#if !defined(__FreeBSD__)
 #   include <malloc.h>
+#else
+#   include <stdlib.h>
+#endif
 #   undef _WIN32
 #   undef WIN32
 #   undef _WIN64
