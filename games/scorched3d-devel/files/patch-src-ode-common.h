--- src/ode/common.h.orig	Wed Jul 30 17:41:29 2003
+++ src/ode/common.h	Sun Aug  3 09:07:13 2003
@@ -25,7 +25,7 @@
 
 #include <ode/config.h>
 #include <ode/error.h>
-#ifndef WIN32
+#if !defined(WIN32) && !defined(__FreeBSD__)
 #include <alloca.h>
 #endif
 #include <stdlib.h>
