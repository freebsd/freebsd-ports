--- Makefile.PL.orig	Wed Aug 18 15:58:18 1999
+++ Makefile.PL	Fri Mar  2 15:50:32 2001
@@ -3,5 +3,5 @@
 WriteMakefile(
 	      'NAME' => 'Text::ChaSen',
 	      'VERSION_FROM' => 'ChaSen.pm',
-	      'LIBS' => ['-lchasen']
+	      'LIBS' => ["-lstdc++ -L$ENV{PREFIX}/lib -lchasen"]
 );
