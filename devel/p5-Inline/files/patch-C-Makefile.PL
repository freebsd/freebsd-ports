diff -ur Inline-0.43.orig/C/Makefile.PL Inline-0.43/C/Makefile.PL
--- Inline-0.43.orig/C/Makefile.PL	Fri Dec 14 18:34:37 2001
+++ Inline-0.43/C/Makefile.PL	Fri Dec 14 18:44:57 2001
@@ -51,26 +51,9 @@
 # '
 }
 
-my $answer = '';
-my $default = $found ? "y" : "n";
-while (1) {
-    $answer = prompt ('Do you want to install Inline::C?', $default); 
-    last if $answer =~ /^(y|yes|n|no)$/i;
-}
-
-if ($answer =~ /^(y|yes)$/i) {
     WriteMakefile(
 	 	  NAME => 'Inline::C',
 		  VERSION_FROM => 'C.pm',
 		  clean => {FILES => '_Inline_test/'},
 		 )
-}
-else {
-    open MF, "> Makefile" or die "Can't open Makefile for output";
-    print MF <<'END';
-all::
-test::
-clean::
-END
-    close MF;
-}
+;
