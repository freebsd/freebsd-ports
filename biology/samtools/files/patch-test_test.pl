--- test/test.pl.orig	2017-10-18 06:08:39 UTC
+++ test/test.pl
@@ -636,7 +636,7 @@ sub test_usage
     my $command = $args{cmd};
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out,$err) = _cmd("$commandpath $args{redirection}");
-    if ( $err =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath: $out"); return; }
+    if ( $err =~ m/\/usr\/local\/bin\/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath: $out"); return; }
 
     my @sections = ($err =~ m/(^[A-Za-z]+.*?)(?:(?=^[A-Za-z]+:)|\z)/msg);
 
@@ -694,7 +694,7 @@ sub test_usage_subcommand
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out,$err) = _cmd("$commandpath $subcommand $args{redirection}");
 
-    if ( $err =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath $subcommand: $out"); return; }
+    if ( $err =~ m/\/usr\/local\/bin\/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath $subcommand: $out"); return; }
 
     if ( $err =~ m/not.*implemented/is ) { failed($opts,msg=>$test,reason=>"subcommand indicates it is not implemented",expect_fail=>1); return; }
 
