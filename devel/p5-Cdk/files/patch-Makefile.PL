--- ./Makefile.PL.orig	2002-07-28 22:09:50.000000000 +0300
+++ ./Makefile.PL	2009-06-05 21:13:48.635138099 +0300
@@ -13,7 +13,7 @@
 WriteMakefile(
     'NAME'	=> 'Cdk',
     'VERSION'	=> '4.09010',
-    'LIBS'	=> ['-L/usr/local/lib -lcdk -lcurses'],
-    'INC'	=> '-I/usr/include/ncurses -I/usr/local/include/cdk',
+    'LIBS'      => ['-L%%LOCALBASE%%/lib -lcdk -lcurses'],
+    'INC'       => '-I/usr/include -I%%LOCALBASE%%/include -I%%LOCALBASE%%/include/cdk',
     'clean'	=> {FILES => 'Makefile.old'},
 );
