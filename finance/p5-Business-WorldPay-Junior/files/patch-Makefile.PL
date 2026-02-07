--- Makefile.PL.orig	Fri Mar 14 11:35:10 2003
+++ Makefile.PL	Sat Mar 15 10:40:05 2003
@@ -3,9 +3,6 @@
 # the contents of the Makefile that is written.
 WriteMakefile(
     'NAME'		=> 'Business::WorldPay::Junior',
-    'VERSION_FROM'	=> 'Junior.pm', # finds $VERSION
+    'VERSION'		=> '1.06',
     'PREREQ_PM'		=> {}, # e.g., Module::Name => 1.1
-    ($] >= 5.005 ?    ## Add these new keywords supported since 5.005
-      (ABSTRACT_FROM => 'Junior.pm', # retrieve abstract from module
-       AUTHOR     => 'Jason Clifford <jason@jasonclifford.com>') : ()),
 );
