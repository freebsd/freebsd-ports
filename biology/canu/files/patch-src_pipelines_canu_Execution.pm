--- src/pipelines/canu/Execution.pm.orig	2017-08-14 19:39:19 UTC
+++ src/pipelines/canu/Execution.pm
@@ -302,10 +302,6 @@ sub skipStage ($$@) {
 sub getInstallDirectory () {
     my $installDir = $FindBin::RealBin;
 
-    if ($installDir =~ m!^(.*)/\w+-\w+/bin$!) {
-        $installDir = $1;
-    }
-
     return($installDir);
 }
 
