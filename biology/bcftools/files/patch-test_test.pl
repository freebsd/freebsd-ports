--- test/test.pl.orig	2020-10-18 13:36:42 UTC
+++ test/test.pl
@@ -1236,7 +1236,7 @@ sub test_usage
     my $command = $args{cmd};
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out) = _cmd("$commandpath $args{redirection} 2>&1");
-    if ( $out =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath: $out"); return; }
+    if ( $out =~ m/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath: $out"); return; }
 
     my @sections = ($out =~ m/(^[A-Za-z]+.*?)(?:(?=^[A-Za-z]+:)|\z)/msg);
 
@@ -1291,7 +1291,7 @@ sub test_usage_subcommand
     my $subcommand = $args{subcmd};
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out) = _cmd("$commandpath $subcommand $args{redirection} 2>&1");
-    if ( $out =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath $subcommand: $out"); return; }
+    if ( $out =~ m/bash.*no.*such/i ) { failed($opts,$test,"could not run $commandpath $subcommand: $out"); return; }
 
     my @sections = ($out =~ m/(^[A-Za-z]+.*?)(?:(?=^[A-Za-z]+:)|\z)/msg);
 
