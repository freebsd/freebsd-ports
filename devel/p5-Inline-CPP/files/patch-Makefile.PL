--- Makefile.PL.orig	2018-09-18 22:19:47 UTC
+++ Makefile.PL
@@ -37,10 +37,10 @@ check_prereqs(\%PREREQ_PM) or warn "!!! 
 my($cc_guess, $libs_guess) = guess_compiler();
 
 my $cpp_compiler
-  = prompt("What C++ compiler would you like to use?", $cc_guess);
+  = $cc_guess;
 
 my $libs
-  = prompt("What default libraries would you like to include?", $libs_guess);
+  = $libs_guess;
 
 configure_distribution($test_cpp_filename, $cpp_compiler, $libs);
 
