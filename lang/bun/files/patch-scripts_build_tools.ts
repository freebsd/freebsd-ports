-- Add FreeBSD support to LLVM toolchain resolution:
-- 1. llvmSearchPaths: add /usr/local/llvmNN/bin (FreeBSD ports layout)
-- 2. resolveLlvmToolchain: use ld.lld for FreeBSD (same as Linux)
-- 3. llvmInstallHint: add FreeBSD install hint
--- scripts/build/tools.ts.orig	2026-04-27 08:09:39 UTC
+++ scripts/build/tools.ts
@@ -312,6 +312,12 @@ function llvmSearchPaths(os: OS, arch: Arch): string[]
     paths.push(`/usr/lib/llvm${LLVM_MAJOR}/bin`);
   }
 
+  if (os === "freebsd") {
+    // FreeBSD ports install LLVM under /usr/local/llvm${MAJOR}/bin
+    paths.push(`/usr/local/llvm${LLVM_MAJOR}/bin`);
+    paths.push(`/usr/local/llvm-${LLVM_MAJOR}/bin`);
+  }
+
   return paths;
 }
 
@@ -332,6 +338,7 @@ function llvmInstallHint(os: OS): string {
   if (os === "darwin") return `Install with: brew install llvm@${LLVM_MAJOR}`;
   if (os === "linux")
     return `Install with: apt install clang-${LLVM_MAJOR} lld-${LLVM_MAJOR}  (or equivalent for your distro)`;
+  if (os === "freebsd") return `Install with: pkg install llvm${LLVM_MAJOR}`;
   if (os === "windows") return `Install LLVM ${LLVM_VERSION} from https://github.com/llvm/llvm-project/releases`;
   return "";
 }
@@ -419,7 +426,7 @@ export function resolveLlvmToolchain(
   let ld: string;
   if (os === "windows") {
     ld = findLlvmTool("lld-link", paths, os, { checkVersion: false, required: true })?.path ?? "";
-  } else if (os === "linux") {
+  } else if (os === "linux" || os === "freebsd") {
     ld = findLlvmTool("ld.lld", paths, os, { checkVersion: true, required: true })?.path ?? "";
   } else {
     ld = ""; // darwin: unused
