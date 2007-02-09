--- ./Makefile.PL.orig	Tue Feb  6 03:22:45 2007
+++ ./Makefile.PL	Fri Feb  9 15:57:13 2007
@@ -14,7 +14,7 @@
 
 WriteMakefile(
     'NAME'		=> 'Net::OICQ',
-    'VERSION_FROM'	=> 'OICQ.pm', # finds $VERSION
+    'VERSION_FROM'	=> 'lib/Net/OICQ.pm', # finds $VERSION
     'PREREQ_PM'		=> {Crypt::OICQ     => 1.0,
                             Digest::MD5     => 0.1,
 		            IO::Select      => 0.1,
@@ -22,7 +22,7 @@
 		    	    Term::ReadKey   => 0,
 		    	},
     ($] >= 5.005 ?    ## Add these new keywords supported since 5.005
-      (ABSTRACT_FROM => 'OICQ.pm', # retrieve abstract from module
+      (ABSTRACT_FROM => 'lib/Net/OICQ.pm', # retrieve abstract from module
        AUTHOR     => 'Shufeng Tan <shufengtan@gmail.com>') : ()),
     'LIBS'		=> [''],
     'DEFINE'		=> '',
