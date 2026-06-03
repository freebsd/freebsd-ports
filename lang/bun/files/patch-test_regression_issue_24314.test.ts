-- Skip gracefully when bun:internal-for-testing is unavailable (release builds).
-- bun:internal-for-testing is only compiled into debug/development builds of bun.
-- FreeBSD ports always build a release binary, so this module is never available.
-- Without this patch, the test file crashes at module load time with ENOENT,
-- causing "Unhandled error between tests" in the bun test output.
--- test/regression/issue/24314.test.ts.orig	2026-04-27 17:51:47 UTC
+++ test/regression/issue/24314.test.ts
@@ -1,4 +1,10 @@
-import { readTarball } from "bun:internal-for-testing";
+// bun:internal-for-testing is only available in debug builds; skip gracefully in release builds.
+let readTarball: ((path: string) => any) | undefined;
+try {
+  ({ readTarball } = require("bun:internal-for-testing") as any);
+} catch {
+  readTarball = undefined;
+}
 import { expect, test } from "bun:test";
 import { bunEnv, bunExe, tempDir } from "harness";
 import path from "node:path";
@@ -8,7 +14,7 @@ function normalizePath(p: string): string {
   return p.replace(/\\/g, "/");
 }
 
-test("bun pm pack respects changes to package.json from prepack scripts", async () => {
+test.skipIf(!readTarball)("bun pm pack respects changes to package.json from prepack scripts", async () => {
   using dir = tempDir("pack-prepack", {
     "package.json": JSON.stringify(
       {
@@ -61,7 +67,7 @@ fs.writeFileSync('package.json', JSON.stringify(pkg, n
   expect(extractedPkg.description).toBe("MODIFIED BY PREPACK");
 });
 
-test("bun pm pack respects changes to package.json from prepare scripts", async () => {
+test.skipIf(!readTarball)("bun pm pack respects changes to package.json from prepare scripts", async () => {
   using dir = tempDir("pack-prepare", {
     "package.json": JSON.stringify(
       {
