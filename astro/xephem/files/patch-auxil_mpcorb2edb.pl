--- auxil/mpcorb2edb.pl.orig	2014-07-11 02:46:35 UTC
+++ auxil/mpcorb2edb.pl
@@ -78,7 +78,7 @@ EOF
 # setup cutoff mag
 my $dimmag = 13;			# dimmest mag to be saved in "bright" file
 # set site and file in case of -f
-my $MPCSITE = "http://www.minorplanetcenter.net";
+my $MPCSITE = "https://www.minorplanetcenter.net";
 my $MPCFTPDIR = "/iau/MPCORB";
 my $MPCFILE = "MPCORB.DAT";
 my $MPCZIPFILE = "MPCORB.DAT.gz";
