--- ../gpgme++/context.cpp.orig	2009-07-01 18:28:59.000000000 -0400
+++ ../gpgme++/context.cpp	2009-07-01 18:30:51.000000000 -0400
@@ -51,6 +51,10 @@
 #include <cassert>
 
 namespace GpgME {
+  void initializeLibrary() {
+      gpgme_check_version( 0 );
+  }
+
   static inline gpgme_error_t makeError( gpg_err_code_t code ) {
     return gpg_err_make( (gpg_err_source_t)22, code );
   }
