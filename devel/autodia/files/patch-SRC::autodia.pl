--- SRC/autodia.pl.orig	Fri Jul  6 21:58:39 2001
+++ SRC/autodia.pl	Sat Oct  6 15:27:45 2001
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -I /home/aaron/downloads/autodia-0.9/SRC
+#!/usr/bin/perl -I /usr/local/lib/perl5/site_perl/5.6.0/autodia
 
 ###############################################################
 # AutoDIA - Automatic Dia XML.   (C)Copyright 2001 A Trevena  #
@@ -156,7 +156,7 @@
 
     $config{filenames}    = \@filenames;
     $config{use_stdout}   = (defined $args{'O'}) ? 1 : 0;
-    $config{templatefile} = (defined $args{'t'}) ? $args{'t'} : "template.xml";
+    $config{templatefile} = (defined $args{'t'}) ? $args{'t'} : "%%LOCALBASE%%/lib/perl5/site_perl/%%PERL_VER%%/autodia/template.xml";
     $config{outputfile}   = (defined $args{'o'}) ? $args{'o'} : "autodial.out.xml";
     $config{no_deps}      = (defined $args{'D'}) ? 1 : 0;
     $config{sort}         = (defined $args{'s'}) ? 1 : 0;
