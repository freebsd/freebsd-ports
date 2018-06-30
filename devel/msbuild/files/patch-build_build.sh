--- build/build.sh.orig	2018-06-25 18:50:41 UTC
+++ build/build.sh
@@ -151,7 +151,7 @@ function ExitIfError {
   then
     echo "$2"
 
-    if [[ "$ci" != "true" && "$dotnetBuildFromSource" != "true" ]]; # kill command not permitted on CI machines or in source-build
+    if [[ "$ci" != "true" && "$dotnetBuildFromSource" != "true" && "$hostType" != "mono" ]]; # kill command not permitted on CI machines or in source-build
     then
       StopProcesses
     fi
@@ -343,7 +343,7 @@ function Build {
 
   local logCmd=$(GetLogCmd Build)
 
-  commonMSBuildArgs="/m /clp:Summary /v:$verbosity /p:Configuration=$configuration /p:SolutionPath=$(QQ $MSBuildSolution) /p:CIBuild=$ci /p:DisableNerdbankVersioning=$dotnetBuildFromSource"
+  commonMSBuildArgs="/m /clp:Summary /v:$verbosity /p:Configuration=$configuration /p:SolutionPath=$(QQ $MSBuildSolution) /p:CIBuild=$ci /p:DisableNerdbankVersioning=true"
 
   # Only enable warnaserror on CI runs.
   if $ci
