--- Makefile.PL.old	Sun Dec 12 05:52:00 2004
+++ Makefile.PL	Wed Feb 16 09:53:41 2005
@@ -147,30 +147,6 @@
   }
 
  RETR:
-  if (($formats{'gif'} or $formats{'ungif'}) && !$ENV{IM_SUPPRESS_PROMPT}) {
-    print <<EOFF;
-
-You have libgif or libungif installed.  They are both known to have
-bugs.  Imager can crash or display other strange behaviour after
-reading or writing gif images.  Some of the gif tests can even fail
-since they stress some parts of the buggy code.
-
-libungif 4.1.2 and later is safe.  giflib 4.1.3 needs at least one
-patch to have all the bugs fixed, see README for details.
-
-Of course it's possible your operating system distributor has patched
-all of these problems and you have nothing to worry about.
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
