--- Makefile.PL.orig	Thu Aug 16 22:50:39 2001
+++ Makefile.PL	Thu Aug 16 22:51:09 2001
@@ -1,6 +1,7 @@
 use ExtUtils::MakeMaker;
 WriteMakefile(
     NAME => "Locale::gettext",
-    LIBS => ["-lintl"],
+    INC => "-I$ENV{LOCALBASE}/include",
+    LIBS => ["-L$ENV{LOCALBASE}/lib -lintl"],
     VERSION_FROM => 'gettext.pm', 
 );
