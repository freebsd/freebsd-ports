--- Makefile.PL.orig	Tue May 27 20:31:10 2003
+++ Makefile.PL	Mon Sep 29 03:09:07 2003
@@ -6,7 +6,7 @@
     'VERSION_FROM' => 'PCSC.pm', # finds $VERSION
     'LIBS'      => [''],   # e.g., '-lm'
     'DEFINE'    => '-O2 -Wall',     # e.g., '-DHAVE_SOMETHING'
-    'INC'       => '-I/usr/local/pcsc/include',     # e.g., '-I/usr/include/other'
+    'INC'       => '-I$(LOCALBASE)/include',     # e.g., '-I/usr/include/other'
 	'PL_FILES'  => {},
 );
 
