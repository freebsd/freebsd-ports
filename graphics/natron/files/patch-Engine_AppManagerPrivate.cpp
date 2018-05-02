--- Engine/AppManagerPrivate.cpp.orig	2017-08-13 15:26:35 UTC
+++ Engine/AppManagerPrivate.cpp
@@ -190,7 +190,7 @@ AppManagerPrivate::createBreakpadHandler(const QString
                                                                       0,
                                                                       true,
                                                                       breakpadPipePath.toStdString().c_str() ) );
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         Q_UNUSED(breakpadPipePath);
         breakpadHandler.reset( new google_breakpad::ExceptionHandler( google_breakpad::MinidumpDescriptor( dumpPath.toStdString() ),
                                                                       0,
@@ -607,7 +607,7 @@ AppManagerPrivate::initGLAPISpecific()
 #ifdef Q_OS_WIN32
     wglInfo.reset(new OSGLContext_wgl_data);
     OSGLContext_win::initWGLData( wglInfo.get() );
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     glxInfo.reset(new OSGLContext_glx_data);
     OSGLContext_x11::initGLXData( glxInfo.get() );
 
@@ -870,7 +870,7 @@ AppManagerPrivate::tearDownGL()
     if (wglInfo) {
         OSGLContext_win::destroyWGLData( wglInfo.get() );
     }
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     if (glxInfo) {
         OSGLContext_x11::destroyGLXData( glxInfo.get() );
     }
