--- Makefile.PL.orig	2006-03-28 22:05:28 UTC
+++ Makefile.PL
@@ -58,7 +58,7 @@
 print q{Do you plan to run the test suite?
 (you will need to set up an *EMPTY* database)};
 
-do { $skip_tests = 1; goto NOTESTS } unless yes();
+do { $skip_tests = 1; goto NOTESTS };
 
 my $configured;
 
