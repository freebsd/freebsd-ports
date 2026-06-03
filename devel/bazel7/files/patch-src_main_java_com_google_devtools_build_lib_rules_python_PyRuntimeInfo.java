--- src/main/java/com/google/devtools/build/lib/rules/python/PyRuntimeInfo.java.orig	1980-01-01 00:00:00 UTC
+++ src/main/java/com/google/devtools/build/lib/rules/python/PyRuntimeInfo.java
@@ -45,7 +45,7 @@ public final class PyRuntimeInfo {
   public static final PyRuntimeInfoProvider PROVIDER = new PyRuntimeInfoProvider();
 
   // Only present so PyRuntimeRule can reference it as a default.
-  static final String DEFAULT_STUB_SHEBANG = "#!/usr/bin/env python3";
+  static final String DEFAULT_STUB_SHEBANG = "#!%%PYTHON_CMD%%";
 
   // Only present so PyRuntimeRule can reference it as a default.
   // Must call getToolsLabel() when using this.
