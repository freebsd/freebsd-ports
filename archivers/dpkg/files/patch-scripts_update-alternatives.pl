--- scripts/update-alternatives.pl.orig	Tue Jun 20 19:36:39 2006
+++ scripts/update-alternatives.pl	Fri Nov 10 13:57:31 2006
@@ -2,6 +2,7 @@
 
 $admindir= "/var/lib/dpkg"; # This line modified by Makefile
 $dpkglibdir= "../utils"; # This line modified by Makefile
+$sysconfdir="/etc"; # This line modified by Makefile
 $version= '0.93.80'; # This line modified by Makefile
 push (@INC, $dpkglibdir);
 require 'dpkg-gettext.pl';
@@ -64,7 +65,7 @@
   --set <name> <path>      set <path> as alternative for <name>.
   --all                    call --config on all alternatives.
 
-<link> is the symlink pointing to /etc/alternatives/<name>.
+<link> is the symlink pointing to $sysconfdir/alternatives/<name>.
   (e.g. /usr/bin/pager)
 <name> is the master name for this link group.
   (e.g. pager)
@@ -97,7 +98,7 @@
     exit(2);
 }
 
-$altdir= '/etc/alternatives';
+$altdir= $sysconfdir . '/alternatives';
 $admindir= $admindir . '/alternatives';
 $testmode= 0;
 $verbosemode= 0;
