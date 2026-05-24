-- Add BUN_HOST_OS environment variable support to override host OS detection.
-- When building with a Linux bootstrap bun binary on FreeBSD, bun reports
-- host.os = "linux" which triggers cross-compilation mode (dep_cargo_cross,
-- rustup target add, cross-compile clang flags). Setting BUN_HOST_OS=freebsd
-- makes the build treat FreeBSD as native, using dep_cargo (no rustup needed)
-- and native LLVM/clang without cross-compile sysroot flags.
--
-- also inline WEBKIT_VERSION to break a circular ES module dependency:
-- deps/index.ts → deps/webkit.ts → source.ts → config.ts → deps/webkit.ts
-- Bun 1.3.14 enforces strict TDZ for circular ES modules; inlining breaks cycle.
--
-- Add support for explicit CPU target via BUN_CPU environment variable or
-- the 'cpu' config field. This allows respecting FreeBSD's CPUTYPE.


--- scripts/build/config.ts.orig	2026-05-12 22:12:49 UTC
+++ scripts/build/config.ts
@@ -11,7 +11,9 @@ import { NODEJS_ABI_VERSION, NODEJS_VERSION } from "./
 import { homedir, arch as hostArch, platform as hostPlatform } from "node:os";
 import { isAbsolute, join, relative, resolve, sep } from "node:path";
 import { NODEJS_ABI_VERSION, NODEJS_VERSION } from "./deps/nodejs-headers.ts";
-import { WEBKIT_VERSION } from "./deps/webkit.ts";
+// WEBKIT_VERSION inlined here (was imported from deps/webkit.ts) to break circular module dep:
+// deps/index.ts → deps/webkit.ts → source.ts → config.ts → deps/webkit.ts
+const WEBKIT_VERSION = "bdf6aab38a9c6f99df3fd1486406ab6b74180fbb";
 import { assert, BuildError } from "./error.ts";
 import { clangTargetArch } from "./tools.ts";
 import { cyan, dim, green } from "./tty.ts";
@@ -116,6 +118,8 @@ export interface Config {
   logs: boolean;
   /** x64-only: target nehalem (no AVX) instead of haswell. */
   baseline: boolean;
+  /** Explicit CPU target (e.g. "native", "skylake"). Overrides baseline/default. */
+  cpu: string | undefined;
   canary: boolean;
   /** MinSizeRel → optimize for size. */
   smol: boolean;
@@ -253,6 +257,7 @@ export interface PartialConfig {
   assertions?: boolean;
   logs?: boolean;
   baseline?: boolean;
+  cpu?: string;
   canary?: boolean;
   staticSqlite?: boolean;
   staticLibatomic?: boolean;
@@ -341,9 +346,12 @@ export interface Toolchain {
 
 /**
  * Host platform detection. Only used for picking defaults.
+ * The BUN_HOST_OS environment variable can override the detected OS.
+ * This is needed when using a Linux bun bootstrap binary on FreeBSD.
  */
 export function detectHost(): Host {
-  const plat = hostPlatform();
+  const envOs = process.env.BUN_HOST_OS;
+  const plat = envOs !== undefined ? envOs : hostPlatform();
   const os: OS =
     plat === "linux"
       ? "linux"
@@ -605,6 +613,7 @@ export function resolveConfig(partial: PartialConfig, 
   const logs = partial.logs ?? debug;
 
   const baseline = partial.baseline ?? false;
+  const cpu = partial.cpu ?? process.env.BUN_CPU;
   const canary = partial.canary ?? true;
   const canaryRevision = canary ? "1" : "0";
 
@@ -779,6 +788,7 @@ export function resolveConfig(partial: PartialConfig, 
     assertions,
     logs,
     baseline,
+    cpu,
     canary,
     smol,
     staticSqlite,
