--- Makefile.PL.orig	Fri Mar  5 10:18:19 2004
+++ Makefile.PL	Fri Mar  5 10:18:41 2004
@@ -14,6 +14,6 @@
     'NAME'	=> 'Cdk',
     'VERSION'	=> '4.09010',
     'LIBS'	=> ['-L/usr/local/lib -lcdk -lcurses'],
-    'INC'	=> '-I/usr/include/ncurses -I/usr/local/include/cdk',
+    'INC'	=> '-I/usr/include -I/usr/local/include',
     'clean'	=> {FILES => 'Makefile.old'},
 );
