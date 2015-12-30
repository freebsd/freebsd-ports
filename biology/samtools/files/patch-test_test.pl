--- test/test.pl.orig	2015-12-22 22:43:15 UTC
+++ test/test.pl
@@ -136,7 +136,7 @@ sub _cmd
     else
     {
         # child
-        exec('/bin/bash', '-o','pipefail','-c', "($cmd) 2> $err_filename") or error("Cannot execute the command [/bin/sh -o pipefail -c $cmd]: $!");
+        exec('/usr/local/bin/bash', '-o','pipefail','-c', "($cmd) 2> $err_filename") or error("Cannot execute the command [/usr/local/bin/bash -o pipefail -c $cmd]: $!");
     }
 }
 sub cmd
@@ -560,7 +560,7 @@ sub test_usage
     my $command = $args{cmd};
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out,$err) = _cmd("$commandpath $args{redirection}");
-    if ( $err =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath: $out"); return; }
+    if ( $err =~ m/\/usr\/local\/bin\/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath: $out"); return; }
 
     my @sections = ($err =~ m/(^[A-Za-z]+.*?)(?:(?=^[A-Za-z]+:)|\z)/msg);
 
@@ -615,7 +615,7 @@ sub test_usage_subcommand
     my $commandpath = $$opts{bin}."/".$command;
     my ($ret,$out,$err) = _cmd("$commandpath $subcommand $args{redirection}");
 
-    if ( $err =~ m/\/bin\/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath $subcommand: $out"); return; }
+    if ( $err =~ m/\/usr\/local\/bin\/bash.*no.*such/i ) { failed($opts,msg=>$test,reason=>"could not run $commandpath $subcommand: $out"); return; }
 
     if ( $err =~ m/not.*implemented/is ) { failed($opts,msg=>$test,reason=>"subcommand indicates it is not implemented",expect_fail=>1); return; }
 
