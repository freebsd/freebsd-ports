--- Makefile.PL.orig	Tue Mar 28 22:05:28 2006
+++ Makefile.PL	Tue May 30 20:47:27 2006
@@ -58,7 +58,7 @@
 print q{Do you plan to run the test suite?
 (you will need to set up an *EMPTY* database)};
 
-do { $skip_tests = 1; goto NOTESTS } unless yes();
+do { $skip_tests = 1; goto NOTESTS };
 
 my $configured;
 
