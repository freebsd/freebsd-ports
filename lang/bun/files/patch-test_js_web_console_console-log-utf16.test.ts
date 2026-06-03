-- Replace toBeEmpty() with toBe("") to avoid matcher pollution from test 16312.
-- Test 16312 calls expect.extend(@testing-library/jest-dom/matchers) globally,
-- which overrides bun's built-in toBeEmpty() with a DOM-only version that rejects
-- strings. When tests run in the same process (bun test --jobs 1), subsequent
-- tests calling toBeEmpty() on string values fail with "value must be an
-- HTMLElement or an SVGElement". Using toBe("") is the correct, unambiguous way
-- to assert an empty string.
--- test/js/web/console/console-log-utf16.test.ts.orig	2026-04-27 17:38:48 UTC
+++ test/js/web/console/console-log-utf16.test.ts
@@ -13,7 +13,7 @@ it("works with large utf-16 strings", async () => {
   const exitCode = await proc.exited;
   const stdout = await proc.stdout.text();
   const stderr = await proc.stderr.text();
-  expect(stderr).toBeEmpty();
+  expect(stderr).toBe("");
   expect(exitCode).toBe(0);
 
   const expected = Array(10000).fill("肉醬意大利粉").join("\n");
