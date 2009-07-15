--- ../gpgme++/global.h.orig	2009-07-01 18:26:50.000000000 -0400
+++ ../gpgme++/global.h	2009-07-01 18:27:58.000000000 -0400
@@ -39,6 +39,8 @@
 
 namespace GpgME {
 
+    GPGMEPP_EXPORT void initializeLibrary();
+
     enum Protocol { OpenPGP, CMS, UnknownProtocol };
 
     enum Engine { GpgEngine, GpgSMEngine, GpgConfEngine, UnknownEngine };
