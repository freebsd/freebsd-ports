--- F77.pm.orig	2022-05-03 14:16:56 UTC
+++ F77.pm
@@ -335,7 +335,7 @@ $F77config{Aix}{DEFAULT}     = 'F77';
 ### FreeBSD ###
 
 if($^O =~ /Freebsd/i) {
-  $gfortran = 'gfortran';
+  $gfortran = 'FB_GFORTRAN';
   $fallback_compiler = 'G77';
 }
 
