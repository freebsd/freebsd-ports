--- ../libkleo/backends/qgpgme/qgpgmebackend.cpp.orig	2009-07-01 18:51:09.000000000 -0400
+++ ../libkleo/backends/qgpgme/qgpgmebackend.cpp	2009-07-01 18:57:10.000000000 -0400
@@ -280,7 +280,7 @@
     mOpenPGPProtocol( 0 ),
     mSMIMEProtocol( 0 )
 {
-
+  GpgME::initializeLibrary();
 }
 
 Kleo::QGpgMEBackend::~QGpgMEBackend() {
