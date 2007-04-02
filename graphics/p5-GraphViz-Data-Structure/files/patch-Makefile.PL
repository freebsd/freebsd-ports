--- Makefile.PL.orig	Tue Sep 27 05:20:28 2005
+++ Makefile.PL	Mon Apr  2 17:27:28 2007
@@ -2,15 +2,6 @@
 use 5.008;
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile that is written.
-my $dot_version = `dot -V 2>&1`;
-
-if (!$dot_version) {
-  die "You must install the graphviz package (http://www.graphviz.org) before using this module.\n";
-}
-else {
-  my ($v) = ($dot_version =~ /dot version (.*?) /);
-  die "You must have at least version 2.2 of dot to use this module" if ($v+0 < 2.2);
-}
 
 WriteMakefile(
     NAME         => 'GraphViz::Data::Structure',
