--- libkdenetwork/gpgmepp/context.h.orig	2009-07-01 19:33:50.000000000 -0400
+++ libkdenetwork/gpgmepp/context.h	2009-07-01 19:36:53.000000000 -0400
@@ -287,6 +287,8 @@
   //
   //
 
+  KDE_EXPORT void initializeLibrary();
+
   KDE_EXPORT GpgME::Error setDefaultLocale( int category, const char * value );
 
   KDE_EXPORT Context * wait( GpgME::Error & e, bool hang=true );
