--- Makefile.PL.orig	Sat Dec  3 21:28:47 2005
+++ Makefile.PL	Sat Dec  3 21:35:59 2005
@@ -11,8 +11,8 @@
 
 unless (conftest("char *x = gettext(\"foo\");", "gettext", 0)) {
 	# try with -lintl
-	$libs = "-lintl";
-	unless (conftest("char *x = gettext(\"foo\");", "gettext", 0)) {
+	$libs = "-L$ENV{LOCALBASE}/lib -lintl -I$ENV{LOCALBASE}/include";
+	unless (conftest("#include <libintl.h>\nchar *x = gettext(\"foo\");", "gettext", 0)) {
 		unlink("conftest.c");
 		unlink("conftest");
 		die "gettext function not found. Please install libintl";
@@ -33,7 +33,8 @@
 
 WriteMakefile(
     NAME => "Locale::gettext",
-    LIBS => ($libs eq '') ? [] : [$libs],
+    LIBS => ($libs eq '') ? [] : ["-L$ENV{LOCALBASE}/lib -lintl"],
+    INC => "-I$ENV{LOCALBASE}/include",
     VERSION_FROM => 'gettext.pm', 
 );
 
