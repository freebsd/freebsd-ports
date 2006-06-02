--- Makefile.PL.orig	Mon Nov 17 23:08:07 2003
+++ Makefile.PL	Fri Jan 27 21:25:46 2006
@@ -5,7 +5,4 @@
     'NAME'		=> 'Java',
     'VERSION_FROM'	=> 'Java.pm', # finds $VERSION
     'PREREQ_PM'		=> {}, # e.g., Module::Name => 1.1
-    'PPM_INSTALL_EXEC'	=> 'perl',
-    'PPM_INSTALL_SCRIPT'=> 'java_server_install.pl',
-	'EXE_FILES'	=> ['java_server_install.pl'],
 );
