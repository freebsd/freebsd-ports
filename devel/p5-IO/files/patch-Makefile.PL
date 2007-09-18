--- Makefile.PL.orig	Tue Sep 18 10:56:13 2007
+++ Makefile.PL	Tue Sep 18 10:56:21 2007
@@ -45,5 +45,4 @@
 					map { "$_ */$_ */*/$_" }
 					qw(*% *.html *.b[ac]k *.old *.orig))
 			   },
-	INSTALLDIRS => 'perl',
 );
