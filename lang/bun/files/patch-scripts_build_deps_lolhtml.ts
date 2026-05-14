-- Disable nightly features and -Zbuild-std for lolhtml as FreeBSD ports use stable Rust.

--- scripts/build/deps/lolhtml.ts.orig	2026-05-14 00:17:32 UTC
+++ scripts/build/deps/lolhtml.ts
@@ -67,7 +67,7 @@ export const lolhtml: Dependency = {
 
     // FreeBSD aarch64 is Tier 3 — no prebuilt std, so -Zbuild-std is
     // required regardless of release/debug.
-    if (cfg.freebsd && cfg.arm64) {
+    if (false && cfg.freebsd && cfg.arm64) {
       spec.buildStd = true;
     }
 
@@ -80,7 +80,7 @@ export const lolhtml: Dependency = {
     // (linux-gnu, darwin, freebsd). musl/android keep the prebuilt-std
     // -Cpanic=abort path.
     const canBuildStdImmediateAbort =
-      cfg.darwin || cfg.freebsd || (cfg.linux && cfg.abi !== "musl" && cfg.abi !== "android");
+      cfg.darwin || (false && cfg.freebsd) || (cfg.linux && cfg.abi !== "musl" && cfg.abi !== "android");
     if (cfg.release && canBuildStdImmediateAbort) {
       spec.buildStd = true;
       spec.rustflags = [
