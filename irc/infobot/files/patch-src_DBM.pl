--- src/DBM.pl.orig	Fri Jul  8 15:43:35 2005
+++ src/DBM.pl	Fri Jul  8 15:43:46 2005
@@ -35,6 +35,7 @@
 =cut
 
 BEGIN { push @INC, 'src' } # baad, bad juju here
+BEGIN { push @INC, '.' }
 
 use vars qw(%DBMS $Debug $Init_done $Old_warnings);
 
