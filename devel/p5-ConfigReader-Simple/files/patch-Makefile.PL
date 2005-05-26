--- Makefile.PL.orig	Sat Apr 30 00:56:58 2005
+++ Makefile.PL	Sat Apr 30 00:57:57 2005
@@ -11,7 +11,8 @@
 		'Test::More'       => '0',
 		},
		                      
+    'MAN3PODS' => { 'lib/ConfigReader/Simple.pm' => 'blib/man3/ConfigReader::Simple.3' },
     clean  => { FILES => "ConfigReader-Simple-*" },
 
 	);
