--- ../kleopatra/main.cpp.orig	2009-07-01 18:44:25.000000000 -0400
+++ ../kleopatra/main.cpp	2009-07-01 18:49:26.000000000 -0400
@@ -75,6 +75,8 @@
 #include <QEventLoop>
 #include <QThreadPool>
 
+#include <gpgme++/global.h>
+
 #include <boost/shared_ptr.hpp>
 
 #include <cassert>
@@ -153,6 +155,8 @@
     QTime timer;
     timer.start();
 
+    GpgME::initializeLibrary();
+
   {
       const unsigned int threads = QThreadPool::globalInstance()->maxThreadCount();
       QThreadPool::globalInstance()->setMaxThreadCount( qMax( 2U, threads ) );
