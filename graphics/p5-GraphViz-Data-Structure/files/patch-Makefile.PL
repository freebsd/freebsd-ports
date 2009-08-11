--- Makefile.PL.orig	2007-09-14 02:17:00.000000000 +0800
+++ Makefile.PL	2009-08-11 20:25:38.000000000 +0800
@@ -8,7 +8,7 @@
   die "You must install the graphviz package (http://www.graphviz.org) before using this module.\n";
 }
 else {
-  my (@v) = ($dot_version =~ /dot (?:- Graphviz )?version (\d+)\.(\d+)/);
+  my (@v) = ($dot_version =~ /dot (?:- Graphviz )?version (\d+)\.(\d+)/i);
   if ( $v[0] < 2 || $v[1] < 2 ) {
     die "You must have at least version 2.2 of dot to use this module (found $v[0].$v[1])";
   }
