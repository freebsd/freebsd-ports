--- certmanager/lib/backends/qgpgme/qgpgmebackend.cpp.orig	2009-07-01 19:41:54.000000000 -0400
+++ certmanager/lib/backends/qgpgme/qgpgmebackend.cpp	2009-07-01 19:42:25.000000000 -0400
@@ -54,7 +54,7 @@
     mOpenPGPProtocol( 0 ),
     mSMIMEProtocol( 0 )
 {
-
+  GpgME::initializeLibrary();
 }
 
 Kleo::QGpgMEBackend::~QGpgMEBackend() {
