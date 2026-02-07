# define ETIME as ETIMEOUT same as done in Mesa
#
--- src/x11/x11-platform.h.orig
+++ src/x11/x11-platform.h
@@ -42,6 +42,10 @@
 #include "config-list.h"
 #include "refcountobj.h"

+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 #ifndef EGL_EXT_platform_xcb
 #define EGL_EXT_platform_xcb 1
 #define EGL_PLATFORM_XCB_EXT              0x31DC
