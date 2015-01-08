--- Makefile.PL.orig	2014-12-26 05:17:26.000000000 +0800
+++ Makefile.PL	2015-01-01 04:23:51.734420696 +0800
@@ -37,10 +37,10 @@
 my( $cc_guess, $libs_guess ) = guess_compiler();
 
 my $cpp_compiler
-  = prompt( "What C++ compiler would you like to use?", $cc_guess );
+  = $cc_guess;
   
 my $libs
-  = prompt( "What default libraries would you like to include?", $libs_guess );
+  = $libs_guess;
 
 configure_distribution( $test_cpp_filename, $cpp_compiler, $libs );
 
