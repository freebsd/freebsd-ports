--- Makefile.PL.orig	Sun Nov  4 16:00:57 2001
+++ Makefile.PL	Sun Nov  4 16:02:00 2001
@@ -143,25 +143,6 @@
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
-
   for my $frm (qw(gif ungif)) {
     checkformat($frm) if ($MANUAL and $formats{$frm});
   }
