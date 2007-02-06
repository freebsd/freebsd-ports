--- scripts/cleanup-info.pl.orig	Tue Jun 20 19:36:39 2006
+++ scripts/cleanup-info.pl	Fri Nov 10 12:22:49 2006
@@ -25,6 +25,7 @@
 # use strict;
 
 my $dpkglibdir = "."; # This line modified by Makefile
+my $prefix = "/usr"; # This line modified by Makefile
 push(@INC,$dpkglibdir);
 require 'dpkg-gettext.pl';
 textdomain("dpkg");
@@ -56,7 +57,7 @@
 "), $0;
 }
 
-my $infodir = '/usr/info';
+my $infodir = "$prefix/info";
 my $unsafe = 0;
 $0 =~ m|[^/]+$|;
 my $name= $&;
