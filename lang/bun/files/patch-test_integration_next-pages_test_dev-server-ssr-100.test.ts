-- Skip gracefully when bun:internal-for-testing is unavailable (release builds).
-- bun:internal-for-testing is only compiled into debug/development builds of bun.
-- FreeBSD ports always build a release binary, so this module is never available.
-- Without this patch, the test file crashes at module load time with ENOENT,
-- causing "Unhandled error between tests" in the bun test output.
--- test/integration/next-pages/test/dev-server-ssr-100.test.ts.orig2026-04-27 17:51:47 UTC
+++ test/integration/next-pages/test/dev-server-ssr-100.test.ts
@@ -1,12 +1,24 @@
 import { Subprocess } from "bun";
-import { install_test_helpers } from "bun:internal-for-testing";
-import { afterAll, beforeAll, expect, test } from "bun:test";
+// bun:internal-for-testing is only available in debug builds; skip gracefully in release builds.
+let install_test_helpers: any;
+try {
+  ({ install_test_helpers } = require("bun:internal-for-testing") as any);
+} catch {
+  install_test_helpers = null;
+}
+import { afterAll, beforeAll, describe, expect, test } from "bun:test";
 import { copyFileSync } from "fs";
 import { cp, rm } from "fs/promises";
 import PQueue from "p-queue";
 import { join } from "path";
 import { StringDecoder } from "string_decoder";
 import { bunEnv, bunExe, tmpdirSync, toMatchNodeModulesAt } from "../../../harness";
+
+if (!install_test_helpers) {
+  describe.skip("next-pages dev server (bun:internal-for-testing unavailable in release builds)", () => {
+    test("skipped", () => {});
+  });
+} else {
 const { parseLockfile } = install_test_helpers;
 
 expect.extend({ toMatchNodeModulesAt });
@@ -172,3 +184,4 @@
   },
   timeout,
 );
+}
