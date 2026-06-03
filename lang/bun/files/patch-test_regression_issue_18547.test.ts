-- Use port: 0 to let the OS assign a random available port.
-- Without this, Bun.serve defaults to port 3000, which causes EADDRINUSE
-- failures when tests run concurrently and another test is also using port 3000.
--- test/regression/issue/18547.test.ts.orig	2026-04-27 18:00:04 UTC
+++ test/regression/issue/18547.test.ts
@@ -2,6 +2,7 @@ test("18547", async () => {
 
 test("18547", async () => {
   using serve = Bun.serve({
+    port: 0,
     routes: {
       "/:foo": request => {
         request.cookies.set("sessionToken", "123456");
