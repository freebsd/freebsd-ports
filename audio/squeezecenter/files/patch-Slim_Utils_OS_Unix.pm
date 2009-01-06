--- Slim/Utils/OS/Unix.pm.orig	2008-12-11 14:13:33.000000000 -0800
+++ Slim/Utils/OS/Unix.pm	2008-12-22 11:05:41.000000000 -0800
@@ -27,7 +27,7 @@
 
 	$class->SUPER::initSearchPath();
 
-	my @paths = (split(/:/, $ENV{'PATH'}), qw(/usr/bin /usr/local/bin /usr/libexec /sw/bin /usr/sbin));
+	my @paths = (split(/:/, $ENV{'PATH'}), qw(/usr/bin /usr/local/bin /usr/local/libexec /usr/libexec /sw/bin /usr/sbin));
 	
 	Slim::Utils::Misc::addFindBinPaths(@paths);
 }
@@ -101,4 +101,4 @@
 # leave log rotation to the system
 sub logRotate {}
 
-1;
\ No newline at end of file
+1;
