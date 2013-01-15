--- ./Makefile.PL.orig	2013-01-01 03:27:22.000000000 +0800
+++ ./Makefile.PL	2013-01-01 03:30:52.000000000 +0800
@@ -121,10 +121,9 @@
 print "This will configure and build Inline::C++.\n";
 
 my $cpp_compiler
-    = prompt( "What default C++ compiler would you like to use?", $cc_guess );
+    = $cc_guess;
 
-my $libs = prompt( "What default libraries would you like to include?",
-    $libs_guess );
+my $libs = $libs_guess;
 
 #============================================================================
 # Test whether the compiler prefers <iostream> or <iostream.h>.
