--- C/Makefile.PL.orig	Mon Oct 28 19:26:08 2002
+++ C/Makefile.PL	Tue May 13 11:52:47 2003
@@ -55,25 +55,7 @@
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
                   clean => {FILES => '_Inline_test'},
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
