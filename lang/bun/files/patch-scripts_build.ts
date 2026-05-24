-- Add 'cpu' to the list of recognized build configuration fields.
-- This allows passing --cpu=<target> to scripts/build.ts to explicitly
-- set the target CPU microarchitecture.

--- scripts/build.ts.orig	2026-05-12 22:12:49 UTC
+++ scripts/build.ts
@@ -363,6 +363,7 @@ function parseArgs(argv: string[]): CliArgs {
     "abi",
     "buildType",
     "mode",
+    "cpu",
     "webkit",
     "buildDir",
     "cacheDir",
@@ -485,7 +486,7 @@ Options:
                                     release-assertions, ci-*
   --<field>=<value>       Override a config field. Boolean fields take
                           on/off/true/false/yes/no/1/0.
-                          Fields: asan, lto, assertions, logs, baseline,
+                          Fields: asan, lto, assertions, logs, baseline, cpu,
                                   canary, valgrind, webkit (prebuilt|local),
                                   buildDir, mode (full|cpp-only|link-only),
                                   unifiedSources, timeTrace
