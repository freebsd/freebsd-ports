-- Disable -baseline suffix for FreeBSD WebKit prebuilt download.
-- FreeBSD only provides a single amd64 WebKit prebuilt which should be
-- used for both baseline and optimized builds.

--- scripts/build/deps/webkit.ts.orig	2026-05-22 23:56:31 UTC
+++ scripts/build/deps/webkit.ts
@@ -62,7 +62,7 @@ function prebuiltSuffix(cfg: Config): string {
   // Linux amd64 (glibc + musl) and Windows amd64. No baseline variant for
   // arm64 or macOS. Suffix order matches the release asset names:
   // bun-webkit-linux-amd64-musl-baseline-lto.tar.gz
-  if (cfg.baseline && cfg.x64) s += "-baseline";
+  if (cfg.baseline && cfg.x64 && !cfg.freebsd) s += "-baseline";
   if (cfg.debug) s += "-debug";
   else if (cfg.lto) s += "-lto";
   if (cfg.asan) s += "-asan";
