-- Fix $.cwd() global state leak from test 10132 into subsequent test files.
-- Test 10132 sets $.cwd() in a test body but never resets it via afterAll.
-- When tests run in the same process (bun test --jobs 1), this leaks the
-- deleted temp dir path as the shell cwd to following test files, causing
-- ENOENT failures in tests 17405 and 17294 that use the bun Shell ($).
--- test/regression/issue/10132.test.ts.orig	2026-04-27 17:36:19 UTC
+++ test/regression/issue/10132.test.ts
@@ -1,5 +1,5 @@ import { $ } from "bun";
 import { $ } from "bun";
-import { beforeAll, expect, test } from "bun:test";
+import { afterAll, beforeAll, expect, test } from "bun:test";
 import { chmodSync } from "fs";
 import { bunExe, isPosix, tempDirWithFiles } from "harness";
 import { join } from "path";
@@ -50,6 +50,11 @@ echo My name is bun-hello2
   }
 });
 
+const originalCwd = process.cwd();
+afterAll(() => {
+  $.cwd(originalCwd);
+});
+
 test("bun run sets cwd for script, matching npm", async () => {
   $.cwd(dir);
   const currentPwd = (await $`${bunExe()} run get-pwd`.text()).trim();
@@ -80,4 +85,5 @@ test("issue #10132, bun run sets PATH", async () => {
       join(dir, "subdir", "one", "two", "three"),
     ].map(run),
   );
+  $.cwd(process.cwd());
 });
