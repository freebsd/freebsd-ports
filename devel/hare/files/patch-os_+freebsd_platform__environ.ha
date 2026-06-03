--- os/+freebsd/platform_environ.ha.orig	2026-02-13 12:18:15 UTC
+++ os/+freebsd/platform_environ.ha
@@ -91,7 +91,7 @@ export fn architecture() arch = {
 // Returns the host CPU architecture.
 export fn architecture() arch = {
 	switch (machine()) {
-	case "aarch64" =>
+	case "arm64" =>
 		return arch::AARCH64;
 	case "riscv64" =>
 		return arch::RISCV64;
