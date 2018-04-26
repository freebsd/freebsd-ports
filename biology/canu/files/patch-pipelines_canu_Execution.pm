$NetBSD$

--- pipelines/canu/Execution.pm.orig	2017-04-17 19:32:38 UTC
+++ pipelines/canu/Execution.pm
@@ -293,10 +293,6 @@ sub skipStage ($$@) {
 sub getInstallDirectory () {
     my $installDir = $FindBin::RealBin;
 
-    if ($installDir =~ m!^(.*)/\w+-\w+/bin$!) {
-        $installDir = $1;
-    }
-
     return($installDir);
 }
 
