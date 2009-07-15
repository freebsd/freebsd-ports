--- libkdenetwork/gpgmepp/context.cpp.orig	2009-07-01 19:33:09.000000000 -0400
+++ libkdenetwork/gpgmepp/context.cpp	2009-07-01 19:35:46.000000000 -0400
@@ -53,6 +53,10 @@
 
 namespace GpgME {
 
+  void initializeLibrary() {
+    gpgme_check_version( 0 );
+  }
+ 
   const char * Error::source() const {
     return gpgme_strsource( (gpgme_error_t)mErr );
   }
