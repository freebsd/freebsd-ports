--- modules/web/src/main/native/Tools/Scripts/webkitdirs.pm.orig	2018-01-16 01:40:56 UTC
+++ modules/web/src/main/native/Tools/Scripts/webkitdirs.pm
@@ -2061,7 +2061,7 @@ sub generateBuildSystemFromCMakeProject
     chdir($buildPath) or die;
 
     # We try to be smart about when to rerun cmake, so that we can have faster incremental builds.
-    my $willUseNinja = canUseNinja() && canUseNinjaGenerator();
+    my $willUseNinja = 0; # canUseNinja() && canUseNinjaGenerator();
     if (-e cmakeCachePath() && -e cmakeGeneratedBuildfile($willUseNinja)) {
         return 0;
     }
