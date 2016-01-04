--- test/test.pl.orig	2015-12-22 22:45:13 UTC
+++ test/test.pl
@@ -290,7 +290,7 @@ sub _cmd
     else
     {
         # child
-        exec('/bin/bash', '-o','pipefail','-c', $cmd) or error("Cannot execute the command [/bin/sh -o pipefail -c $cmd]: $!");
+        exec('/usr/local/bin/bash', '-o','pipefail','-c', $cmd) or error("Cannot execute the command [/usr/local/bin/sh -o pipefail -c $cmd]: $!");
     }
     return ($? >> 8, join('',@out));
 }
@@ -657,7 +657,7 @@ sub test_usage
     my $command = $args{cmd};
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out) = _cmd("$commandpath $args{redirection} 2>&1");
-    if ( $out =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath: $out"); return; }
+    if ( $out =~ m/\/usr\/local\/bin\/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath: $out"); return; }
 
     my @sections = ($out =~ m/(^[A-Za-z]+.*?)(?:(?=^[A-Za-z]+:)|\z)/msg);
 
@@ -708,7 +708,7 @@ sub test_usage_subcommand
     my $subcommand = $args{subcmd};
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out) = _cmd("$commandpath $subcommand $args{redirection} 2>&1");
-    if ( $out =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath $subcommand: $out"); return; }
+    if ( $out =~ m/\/usr\/local\/bin\/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath $subcommand: $out"); return; }
 
     my @sections = ($out =~ m/(^[A-Za-z]+.*?)(?:(?=^[A-Za-z]+:)|\z)/msg);
 
