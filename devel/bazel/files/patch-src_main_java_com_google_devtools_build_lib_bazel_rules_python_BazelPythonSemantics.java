--- src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java.orig	1980-01-01 05:00:00 UTC
+++ src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java
@@ -249,9 +249,8 @@ public class BazelPythonSemantics implements PythonSem
       // TODO(b/234923262): Take exec_group into consideration when selecting sh tools
       if (OS.getCurrent() != OS.WINDOWS) {
         PathFragment shExecutable = ShToolchain.getPathForHost(ruleContext.getConfiguration());
-        String pythonExecutableName = "python3";
-        // NOTE: keep the following line intact to support nix builds
-        String pythonShebang = "#!/usr/bin/env " + pythonExecutableName;
+        String pythonExecutableName = "%%PYTHON_CMD%%";
+        String pythonShebang = "#!" + pythonExecutableName;
         ruleContext.registerAction(
             new SpawnAction.Builder()
                 .addInput(zipFile)
