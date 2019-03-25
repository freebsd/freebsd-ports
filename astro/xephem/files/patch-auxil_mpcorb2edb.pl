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
@@ -247,7 +247,7 @@ sub fetch
 {
     # transfer
     print "Getting $MPCFTPDIR/$MPCZIPFILE from $MPCSITE...\n";
-    $cmd = "curl -connect-timeout 10 -s -u 'anonymous:xephem\@clearskyinstitute.com' $MPCSITE/$MPCFTPDIR/$MPCZIPFILE > $MPCZIPFILE";
+    $cmd = "curl --connect-timeout 10 -s -u 'anonymous:xephem\@clearskyinstitute.com' $MPCSITE/$MPCFTPDIR/$MPCZIPFILE > $MPCZIPFILE";
     print "$cmd\n";
     !system "$cmd" or exit(1);
 
