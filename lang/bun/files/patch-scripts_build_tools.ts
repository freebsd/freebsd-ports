-- Add FreeBSD support to LLVM toolchain resolution:
-- 1. llvmSearchPaths: add /usr/local/llvmNN/bin (FreeBSD ports layout)
-- 2. resolveLlvmToolchain: use ld.lld for FreeBSD (same as Linux)
-- 3. llvmInstallHint: add FreeBSD install hint

--- scripts/build/tools.ts.orig	2026-10-04 00:00:00 UTC
+++ scripts/build/tools.ts	2026-10-04 00:00:00 UTC
@@ -345,6 +345,12 @@
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
 
@@ -365,6 +371,7 @@
   if (os === "darwin") return `Install with: brew install llvm@${LLVM_MAJOR}`;
   if (os === "linux")
     return `Install with: apt install clang-${LLVM_MAJOR} lld-${LLVM_MAJOR}  (or equivalent for your distro)`;
+  if (os === "freebsd") return `Install with: pkg install llvm${LLVM_MAJOR}`;
   if (os === "windows") return `Install LLVM ${LLVM_VERSION} from https://github.com/llvm/llvm-project/releases`;
   return "";
 }
@@ -515,7 +522,7 @@
   let ld: string;
   if (msvcTarget) {
     ld = findLlvmTool("lld-link", paths, os, { checkVersion: false, required: true })?.path ?? "";
-  } else if (os === "linux") {
+  } else if (os === "linux" || os === "freebsd") {
     ld = findLlvmTool("ld.lld", paths, os, { checkVersion: true, required: true })?.path ?? "";
   } else {
     ld = ""; // darwin: unused
