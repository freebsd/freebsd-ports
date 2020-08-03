--- test/test.pl.orig	2020-07-21 20:49:56 UTC
+++ test/test.pl
@@ -610,7 +610,7 @@ sub _cmd
     else
     {
         # child
-        exec('/bin/bash', '-o','pipefail','-c', $cmd) or error("Cannot execute the command [/bin/sh -o pipefail -c $cmd]: $!");
+        exec('bash', '-o','pipefail','-c', $cmd) or error("Cannot execute the command [/usr/local/bin/sh -o pipefail -c $cmd]: $!");
     }
     return ($? >> 8, join('',@out));
 }
@@ -622,7 +622,7 @@ sub _cmd3
     my $pid = fork();
     if ( !$pid )
     {
-        exec('/bin/bash', '-o','pipefail','-c', "($cmd) 2>$tmp.e >$tmp.o");
+        exec('bash', '-o','pipefail','-c', "($cmd) 2>$tmp.e >$tmp.o");
     }
     waitpid($pid,0);
 
@@ -1063,7 +1063,7 @@ sub test_usage
     my $command = $args{cmd};
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out) = _cmd("$commandpath $args{redirection} 2>&1");
-    if ( $out =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath: $out"); return; }
+    if ( $out =~ m/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath: $out"); return; }
 
     my @sections = ($out =~ m/(^[A-Za-z]+.*?)(?:(?=^[A-Za-z]+:)|\z)/msg);
 
@@ -1118,7 +1118,7 @@ sub test_usage_subcommand
     my $subcommand = $args{subcmd};
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out) = _cmd("$commandpath $subcommand $args{redirection} 2>&1");
-    if ( $out =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath $subcommand: $out"); return; }
+    if ( $out =~ m/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath $subcommand: $out"); return; }
 
     my @sections = ($out =~ m/(^[A-Za-z]+.*?)(?:(?=^[A-Za-z]+:)|\z)/msg);
 
