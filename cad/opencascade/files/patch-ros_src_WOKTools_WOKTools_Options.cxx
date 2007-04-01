--- ros/src/WOKTools/WOKTools_Options.cxx.orig	Fri Sep 21 10:08:54 2001
+++ ros/src/WOKTools/WOKTools_Options.cxx	Fri Aug 11 22:00:09 2006
@@ -52,6 +52,8 @@
   myerrflg  = Standard_False;
 #if !defined( WNT ) && !defined( __GNUC__ )
   optind    = 1;
+#elif defined(__FreeBSD__)
+  optind    = 1;
 #else
   optind    = 0;
 #endif  // WNT
