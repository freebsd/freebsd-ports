--- ./C/Makefile.PL.orig	2011-12-11 11:11:56.192084758 -0500
+++ ./C/Makefile.PL	2011-12-11 11:13:06.814083971 -0500
@@ -68,10 +68,10 @@
 # '
 }
 
-my $answer = '';
+my $answer = 'y';
 my $default = $found ? "y" : "n";
 while (1) {
-    $answer = prompt ('Do you want to install Inline::C?', $default);
+    #$answer = prompt ('Do you want to install Inline::C?', $default);
     last if $answer =~ /^(y|yes|n|no)$/i;
 }
 
