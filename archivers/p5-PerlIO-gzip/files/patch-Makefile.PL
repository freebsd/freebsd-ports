--- ./Makefile.PL.orig	2006-10-01 23:28:25.000000000 +0200
+++ ./Makefile.PL	2014-06-02 14:53:46.000000000 +0200
@@ -4,7 +4,7 @@
 use ExtUtils::MakeMaker;
 use Config;
 
-unless ($Config{useperlio} eq 'define' and $Config{usesfio} eq 'false') {
+unless ($Config{useperlio} eq 'define') {
   die <<BARF;
 You need perl 5.8.0 or later, configured to use perlio (and not to use sfio)
 BARF
