--- modules/web/src/main/native/Tools/Scripts/webkitdirs.pm.orig	2018-07-27 01:38:45 UTC
+++ modules/web/src/main/native/Tools/Scripts/webkitdirs.pm
@@ -2148,7 +2148,7 @@ sub generateBuildSystemFromCMakeProject
     chdir($buildPath) or die;
 
     # We try to be smart about when to rerun cmake, so that we can have faster incremental builds.
-    my $willUseNinja = canUseNinja();
+    my $willUseNinja = 0; # canUseNinja();
     if (-e cmakeCachePath() && -e cmakeGeneratedBuildfile($willUseNinja)) {
         return 0;
     }
