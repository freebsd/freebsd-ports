--- Makefile.PL.orig	Tue Mar  7 08:37:40 2006
+++ Makefile.PL	Mon Jun  5 23:31:13 2006
@@ -2,7 +2,11 @@
 use ExtUtils::MakeMaker;
 use Config;
 
-my %args = map { split /\s*=\s*/ } @ARGV;
+my %args;
+foreach $_ (@ARGV){
+    m/(.*?)=(.*)/;
+    $args{$1} = $2;
+}
 
 # purge @ARGV of CCFLAGS
 
