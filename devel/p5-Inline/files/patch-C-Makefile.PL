--- C/Makefile.PL.orig	Sat May 17 17:04:50 2003
+++ C/Makefile.PL	Sat May 17 17:07:39 2003
@@ -55,9 +55,9 @@
 # '
 }
 
-my $answer = '';
+my $answer = 'y';
 my $default = $found ? "y" : "n";
-while (1) {
+while (0) {
     $answer = prompt ('Do you want to install Inline::C?', $default); 
     last if $answer =~ /^(y|yes|n|no)$/i;
 }
