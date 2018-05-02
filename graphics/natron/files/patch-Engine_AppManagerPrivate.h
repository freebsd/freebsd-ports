--- Engine/AppManagerPrivate.h.orig	2017-08-13 15:26:35 UTC
+++ Engine/AppManagerPrivate.h
@@ -52,7 +52,7 @@ GCC_DIAG_ON(deprecated)
 #endif
 #endif
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 #include "Engine/OSGLContext_x11.h"
 #elif defined(Q_OS_WIN32)
 #include "Engine/OSGLContext_win.h"
@@ -184,7 +184,7 @@ struct AppManagerPrivate (public)
 #ifdef Q_OS_WIN32
     boost::scoped_ptr<OSGLContext_wgl_data> wglInfo;
 #endif
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     boost::scoped_ptr<OSGLContext_glx_data> glxInfo;
 #endif
 
