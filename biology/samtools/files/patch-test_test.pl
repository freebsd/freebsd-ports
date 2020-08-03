--- test/test.pl.orig	2020-07-21 20:48:50 UTC
+++ test/test.pl
@@ -907,7 +907,7 @@ sub test_usage
     my $command = $args{cmd};
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out,$err) = _cmd("$commandpath $args{redirection}");
-    if ( $err =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath: $out"); return; }
+    if ( $err =~ m/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath: $out"); return; }
 
     my @sections = ($err =~ m/(^[A-Za-z]+.*?)(?:(?=^[A-Za-z]+:)|\z)/msg);
 
@@ -965,7 +965,7 @@ sub test_usage_subcommand
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out,$err) = _cmd("$commandpath $subcommand $args{redirection}");
 
-    if ( $err =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath $subcommand: $out"); return; }
+    if ( $err =~ m/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath $subcommand: $out"); return; }
 
     if ( $err =~ m/not.*implemented/is ) { failed($opts,msg=>$test,reason=>"subcommand indicates it is not implemented",expect_fail=>1); return; }
 
