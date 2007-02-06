--- scripts/dpkg-shlibdeps.pl.orig	Fri Nov 10 12:02:38 2006
+++ scripts/dpkg-shlibdeps.pl	Fri Nov 10 12:54:26 2006
@@ -3,16 +3,18 @@
 # dpkg-shlibdeps
 # $Id: dpkg-shlibdeps.pl,v 1.19.2.2 2004/04/25 17:11:41 keybuk Exp $
 
-my $dpkglibdir="/usr/lib/dpkg";
+my $dpkglibdir="/usr/lib/dpkg"; # This line modified by Makefile
+my $admindir="/var/lib/dpkg"; # This line modified by Makefile
+my $sysconfdir="/etc"; # This line modified by Makefile
 my $version="1.4.1.19"; # This line modified by Makefile
 
 use English;
 use POSIX qw(:errno_h :signal_h);
 
-my $shlibsoverride= '/etc/dpkg/shlibs.override';
-my $shlibsdefault= '/etc/dpkg/shlibs.default';
+my $shlibsoverride= "$sysconfdir/dpkg/shlibs.override";
+my $shlibsdefault= "$sysconfdir/etc/dpkg/shlibs.default";
 my $shlibslocal= 'debian/shlibs.local';
-my $shlibsppdir= '/var/lib/dpkg/info';
+my $shlibsppdir= "$admindir/info";
 my $shlibsppext= '.shlibs';
 my $varnameprefix= 'shlibs';
 my $dependencyfield= 'Depends';
