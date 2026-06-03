-- Skip the TinyCC-based FFI test on FreeBSD; TinyCC is intentionally disabled
-- on FreeBSD (config.ts: tinycc = !(... || freebsd)).
--- test/regression/issue/20144/20144.test.ts.orig	2026-04-27 17:31:21 UTC
+++ test/regression/issue/20144/20144.test.ts
@@ -2,7 +2,7 @@ import { spawn } from "node:child_process";
 import assert from "node:assert";
 import { spawn } from "node:child_process";
 
-it.skipIf(process.platform === "win32")("should not time out", done => {
+it.skipIf(process.platform === "win32" || process.platform === "freebsd")("should not time out", done => {
   const child = spawn(process.execPath, ["run", "./20144.fixture.ts"], {
     cwd: __dirname,
     stdio: [null, "inherit", "inherit", "ipc"],
