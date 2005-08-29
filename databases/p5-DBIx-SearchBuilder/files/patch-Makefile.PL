--- Makefile.PL.orig	Mon Aug 29 11:18:58 2005
+++ Makefile.PL	Mon Aug 29 11:19:03 2005
@@ -21,7 +21,6 @@
 	  'Class::Accessor' => '',
 	],
 );
-auto_install();
 
 &Makefile->write;
 &Meta->write;
