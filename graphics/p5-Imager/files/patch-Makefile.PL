--- Makefile.PL.orig	Tue Jul 24 20:48:12 2001
+++ Makefile.PL	Tue Jul 24 20:51:11 2001
@@ -141,24 +141,6 @@
   }
 
  RETR:
-  if ($formats{'gif'} or $formats{'ungif'}) {
-    print <<EOFF;
-
-You have libgif or libungif installed.  They are both known to have
-bugs.  Imager can crash or display other strange behaviour after
-reading or writing gif images.  Some of the gif tests can even fail
-since they stress some parts of the buggy code.
-
-Do you want to remove gif support? [Y/n]
-EOFF
-    my $resp = <STDIN>;
-    chomp($resp);
-    if ($resp ne "n") {
-      delete $formats{'gif'};
-      delete $formats{'ungif'};
-      return;
-    }
-  }
 
   for my $frm (qw(gif ungif)) {
     checkformat($frm) if ($MANUAL and $formats{$frm});
