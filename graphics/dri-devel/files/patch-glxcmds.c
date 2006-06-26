--- src/glx/x11/glxcmds.c.orig	Mon Jun 26 12:34:05 2006
+++ src/glx/x11/glxcmds.c	Mon Jun 26 12:35:42 2006
@@ -56,6 +56,12 @@
 #include "glheader.h"
 #include <sys/time.h>
 
+/* Workaround for stale headers in FreeBSD ports.  Remove when 7.1 lands. */
+#ifndef X_GLXvop_BindTexImageEXT
+#define X_GLXvop_BindTexImageEXT                5152
+#define X_GLXvop_ReleaseTexImageEXT             5153
+#endif
+
 static const char __glXGLXClientVendorName[] = "SGI";
 static const char __glXGLXClientVersion[] = "1.4";
 
