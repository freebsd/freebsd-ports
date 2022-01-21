--- src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java.orig	1979-12-31 23:00:00 UTC
+++ src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java
@@ -238,9 +238,8 @@
 
       if (OS.getCurrent() != OS.WINDOWS) {
         PathFragment shExecutable = ShToolchain.getPathOrError(ruleContext);
-        String pythonExecutableName = "python3";
-        // NOTE: keep the following line intact to support nix builds
-        String pythonShebang = "#!/usr/bin/env " + pythonExecutableName;
+        String pythonExecutableName = "%%PYTHON_CMD%%";
+        String pythonShebang = "#!" + pythonExecutableName;
         ruleContext.registerAction(
             new SpawnAction.Builder()
                 .addInput(zipFile)
