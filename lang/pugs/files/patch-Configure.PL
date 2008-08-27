--- Configure.PL.orig	2008-08-26 09:12:29.000000000 +0800
+++ Configure.PL	2008-08-26 10:01:03.000000000 +0800
@@ -66,10 +66,12 @@
     else {
         $embed_flags .= " -optc$_" for grep length, split(/\s+/, ccopts());
         $embed_flags .= " -optl$_" for grep length, split(/\s+/, ldopts());
+	$embed_flags =~ s/-optl-pthread(.*?)? //g;
     }
 
     $embed_flags .= " $_" for grep { /-[DIL]/ } split(/\s+/, ccopts());
     $embed_flags .= " $_" for grep { /-[DIL]/ } split(/\s+/, ldopts());
+    $embed_flags =~ s/-pthread(.*?)? //g;
 
     if ($Config{osname} eq 'cygwin') {
         my $cygpath = sub {
