--- Makefile.PL.old	Tue Jul 25 11:25:29 2006
+++ Makefile.PL	Tue Jul 25 11:26:39 2006
@@ -259,31 +259,6 @@
   }
 
  RETR:
-  if (($formats{'gif'} or $formats{'ungif'}) && !$ENV{IM_SUPPRESS_PROMPT}) {
-    my $msg = <<EOFF;
-
-You have libgif or libungif installed.  They are both known to have
-bugs.  Imager can crash or display other strange behaviour after
-reading or writing gif images.  Some of the gif tests can fail since
-they stress some parts of the buggy code.
-
-libungif or libgif 4.1.4 and later is safe.
-
-Of course it's possible your operating system distributor has patched
-all of these problems and you have nothing to worry about.
-
-Do you want to remove gif support? [Y/n]
-EOFF
-    chomp $msg;
-    my $resp = prompt($msg);
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
