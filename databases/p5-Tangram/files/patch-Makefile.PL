--- Makefile.PL.orig	Mon Apr  8 15:33:42 2002
+++ Makefile.PL	Mon Apr  8 15:35:06 2002
@@ -24,7 +24,7 @@
 print q{Do you plan to run the regression tests?
 (you will need to set up an *EMPTY* database)};
 
-goto NOTESTS unless yes();
+goto NOTESTS;
 
 my $configured;
 
