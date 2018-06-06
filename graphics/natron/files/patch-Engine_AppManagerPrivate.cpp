--- Engine/AppManagerPrivate.cpp.orig	2018-05-23 13:32:30.000000000 +0200
+++ Engine/AppManagerPrivate.cpp	2018-06-06 10:16:23.029583000 +0200
@@ -191,7 +191,7 @@ AppManagerPrivate::createBreakpadHandler(const QString
                                                                                  (void*)NULL,
                                                                                  true,
                                                                                  breakpadPipePath.toStdString().c_str() );
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         Q_UNUSED(breakpadPipePath);
         breakpadHandler = boost::make_shared<google_breakpad::ExceptionHandler>( google_breakpad::MinidumpDescriptor( dumpPath.toStdString() ),
                                                                                  google_breakpad::ExceptionHandler::FilterCallback(NULL),
@@ -616,7 +616,7 @@ AppManagerPrivate::initGLAPISpecific()
     // scoped_ptr
     wglInfo.reset(new OSGLContext_wgl_data);
     OSGLContext_win::initWGLData( wglInfo.get() );
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     // scoped_ptr
     glxInfo.reset(new OSGLContext_glx_data);
     OSGLContext_x11::initGLXData( glxInfo.get() );
@@ -994,7 +994,7 @@ AppManagerPrivate::tearDownGL()
     if (wglInfo) {
         OSGLContext_win::destroyWGLData( wglInfo.get() );
     }
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     if (glxInfo) {
         OSGLContext_x11::destroyGLXData( glxInfo.get() );
     }
