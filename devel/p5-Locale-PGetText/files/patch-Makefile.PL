--- Makefile.PL.orig	Fri Jan 28 15:18:53 2000
+++ Makefile.PL	Fri Jan 28 15:19:04 2000
@@ -1,5 +1,6 @@
 use ExtUtils::MakeMaker;
 WriteMakefile(
+    PREFIX => "/usr/local",
     NAME => "Locale::PGetText",
     VERSION_FROM => 'PGetText.pm', 
     EXE_FILES => [ 'MsgFormat','XText' ],
