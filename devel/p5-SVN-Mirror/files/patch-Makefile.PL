--- Makefile.PL.orig	2008-09-12 16:21:11 UTC
+++ Makefile.PL
@@ -32,6 +32,3 @@ include('ExtUtils::AutoInstall');
 auto_install();
 #sign(1);
 WriteAll( sign => 1);
-
-die "SVN::Core $required_svn must be manually installed"
-    unless eval {require SVN::Core} && $SVN::Core::VERSION >= $required_svn;
