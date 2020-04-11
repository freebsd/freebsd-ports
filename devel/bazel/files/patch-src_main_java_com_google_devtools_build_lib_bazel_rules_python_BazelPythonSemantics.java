--- src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java.orig	2020-03-03 17:09:23 UTC
+++ src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java
@@ -237,15 +237,15 @@ public class BazelPythonSemantics implem
         PathFragment shExecutable = ShToolchain.getPathOrError(ruleContext);
         // TODO(#8685): Remove this special-case handling as part of making the proper shebang a
         // property of the Python toolchain configuration.
-        String pythonExecutableName = OS.getCurrent() == OS.OPENBSD ? "python3" : "python";
+        String pythonExecutable = "%%PYTHON_CMD%%";
         ruleContext.registerAction(
             new SpawnAction.Builder()
                 .addInput(zipFile)
                 .addOutput(executable)
                 .setShellCommand(
                     shExecutable,
-                    "echo '#!/usr/bin/env "
-                        + pythonExecutableName
+                    "echo '#!"
+                        + pythonExecutable
                         + "' | cat - "
                         + zipFile.getExecPathString()
                         + " > "
