--- tools/jdk/default_java_toolchain.bzl.orig	1980-01-01 00:00:00.000000000 +0100
+++ tools/jdk/default_java_toolchain.bzl	2018-10-30 00:09:06.904725000 +0100
@@ -19,29 +19,7 @@
 ]
 
 JDK9_JVM_OPTS = [
-    # In JDK9 we have seen a ~30% slow down in JavaBuilder performance when using
-    # G1 collector and having compact strings enabled.
-    "-XX:+UseParallelOldGC",
-    "-XX:-CompactStrings",
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
-    "--patch-module=java.compiler=$(location @bazel_tools//third_party/java/jdk/langtools:java_compiler_jar)",
-    "--patch-module=jdk.compiler=$(location @bazel_tools//third_party/java/jdk/langtools:jdk_compiler_jar)",
-
-    # quiet warnings from com.google.protobuf.UnsafeUtil,
-    # see: https://github.com/google/protobuf/issues/3781
-    # and: https://github.com/bazelbuild/bazel/issues/5599
-    "--add-opens=java.base/java.nio=ALL-UNNAMED",
-    "--add-opens=java.base/java.lang=ALL-UNNAMED",
+    "-Xbootclasspath/p:$(location @bazel_tools//third_party/java/jdk/langtools:javac_jar)",
 ]
 
 DEFAULT_JAVACOPTS = [
@@ -74,7 +52,7 @@
         "@bazel_tools//third_party/java/jdk/langtools:jdk_compiler_jar",
     ],
     "javac_supports_workers": 1,
-    "jvm_opts": JDK9_JVM_OPTS,
+    "jvm_opts": JDK8_JVM_OPTS,
     "misc": DEFAULT_JAVACOPTS,
     "compatible_javacopts": COMPATIBLE_JAVACOPTS,
     "singlejar": ["@bazel_tools//tools/jdk:singlejar"],
