Issutracker : #i41144#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : canonical name by config.guess for FreeBSD is
% ./config.guess
i386-unknown-freebsd5.3
so, $main::operatingSystem is
% ./config.guess | cut -d"-" -f3,4
freebsd5.3
then, if ( $main::operatingSystem eq "FreeBSD" ) is not correct,
and if ( $main::operatingSystem =~ /freebsd/ ) is correct

Index: odk/configure.pl
===================================================================
RCS file: /cvs/api/odk/configure.pl,v
retrieving revision 1.11
diff -u -r1.11 configure.pl
--- odk/configure.pl	29 Mar 2005 12:03:00 -0000	1.11
+++ odk/configure.pl	15 May 2005 08:46:20 -0000
@@ -45,7 +45,7 @@
 
 $main::OO_SDK_MAKE_HOME = "";
 $main::makeName = "make";
-if ( $main::operatingSystem eq "FreeBSD" )
+if ( $main::operatingSystem =~ /freebsd/ )
 {
     $main::makeName = "gmake";
 }
