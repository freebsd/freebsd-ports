--- src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java.orig	2020-07-03 15:30:52.313535000 +0200
+++ src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java	2020-07-03 15:31:54.048865000 +0200
@@ -247,9 +247,9 @@
         PathFragment shExecutable = ShToolchain.getPathOrError(ruleContext);
         // TODO(#8685): Remove this special-case handling as part of making the proper shebang a
         // property of the Python toolchain configuration.
-        String pythonExecutableName = OS.getCurrent() == OS.OPENBSD ? "python3" : "python";
+        String pythonExecutableName = "%%PYTHON_CMD%%";
         // NOTE: keep the following line intact to support nix builds
-        String pythonShebang = "#!/usr/bin/env " + pythonExecutableName;
+        String pythonShebang = "#!" + pythonExecutableName;
         ruleContext.registerAction(
             new SpawnAction.Builder()
                 .addInput(zipFile)
