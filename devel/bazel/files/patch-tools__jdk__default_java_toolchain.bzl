--- tools/jdk/default_java_toolchain.bzl.orig	1979-12-31 23:00:00 UTC
+++ tools/jdk/default_java_toolchain.bzl
@@ -21,25 +21,6 @@ JDK8_JVM_OPTS = [
 ]
 
 JDK9_JVM_OPTS = [
-    # Allow JavaBuilder to access internal javac APIs.
-    "--add-exports=jdk.compiler/com.sun.tools.javac.api=ALL-UNNAMED",
-    "--add-exports=jdk.compiler/com.sun.tools.javac.code=ALL-UNNAMED",
-    "--add-exports=jdk.compiler/com.sun.tools.javac.comp=ALL-UNNAMED",
-    "--add-exports=jdk.compiler/com.sun.tools.javac.file=ALL-UNNAMED",
-    "--add-exports=jdk.compiler/com.sun.tools.javac.main=ALL-UNNAMED",
-    "--add-exports=jdk.compiler/com.sun.tools.javac.tree=ALL-UNNAMED",
-    "--add-exports=jdk.compiler/com.sun.tools.javac.util=ALL-UNNAMED",
-    "--add-opens=jdk.compiler/com.sun.tools.javac.file=ALL-UNNAMED",
-
-    # override the javac in the JDK.
-    "--patch-module=java.compiler=$(location @bazel_tools//tools/jdk:java_compiler_jar)",
-    "--patch-module=jdk.compiler=$(location @bazel_tools//tools/jdk:jdk_compiler_jar)",
-
-    # quiet warnings from com.google.protobuf.UnsafeUtil,
-    # see: https://github.com/google/protobuf/issues/3781
-    # and: https://github.com/bazelbuild/bazel/issues/5599
-    "--add-opens=java.base/java.nio=ALL-UNNAMED",
-    "--add-opens=java.base/java.lang=ALL-UNNAMED",
 ]
 
 DEFAULT_JAVACOPTS = [
@@ -63,7 +44,7 @@ DEFAULT_TOOLCHAIN_CONFIGURATION = {
     "javac_supports_workers": 1,
     "jvm_opts": select({
         "@bazel_tools//src/conditions:openbsd": JDK8_JVM_OPTS,
-        "//conditions:default": JDK9_JVM_OPTS,
+        "//conditions:default": JDK8_JVM_OPTS,
     }),
     "misc": DEFAULT_JAVACOPTS,
     "singlejar": ["@bazel_tools//tools/jdk:singlejar"],
