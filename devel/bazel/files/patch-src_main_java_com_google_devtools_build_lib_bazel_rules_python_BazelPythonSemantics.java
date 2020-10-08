--- src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java.orig	1979-12-31 23:00:00 UTC
+++ src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java
@@ -247,9 +247,9 @@ public class BazelPythonSemantics implem
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
