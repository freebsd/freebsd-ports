--- scripts/install-info.pl.orig	Tue Jun 20 19:36:39 2006
+++ scripts/install-info.pl	Fri Nov 10 15:33:54 2006
@@ -3,6 +3,8 @@
 use Text::Wrap;
 
 my $dpkglibdir = "."; # This line modified by Makefile
+my $prefix = "/usr"; # This line modified by Makefile
+my $infodir = "/usr/share/info"; # This line modified by Makefile
 push (@INC, $dpkglibdir);
 require 'dpkg-gettext.pl';
 textdomain("dpkg");
@@ -51,11 +53,11 @@
 "), $0;
 }
 
-$dirfile = '/usr/share/info/dir';
+$dirfile = "$infodir/dir";
 $maxwidth=79;
 $Text::Wrap::columns=$maxwidth;
 $backup='/var/backups/infodir.bak';
-$default='/usr/share/base-files/info.dir';
+$default="$prefix/share/base-files/info.dir";
 
 $menuentry="";
 $description="";
