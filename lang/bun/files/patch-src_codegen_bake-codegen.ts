-- Replace Bun.spawnSync with async Bun.spawn in bake-codegen.
-- On FreeBSD linux compat layer, Bun.spawnSync with stdio:"pipe" fails
-- with EINVAL because pread() is not valid on pipes. Using async Bun.spawn
-- with Response.arrayBuffer() works correctly on FreeBSD linux compat.

	2026-04-27 07:15:02 UTC
+++ src/codegen/bake-codegen.ts
@@ -30,20 +30,27 @@ function convertZigEnum(zig: string, names: string[]) 
   return output;
 }
 
-function css(file: string, is_development: boolean): string {
-  const { success, stdout, stderr } = Bun.spawnSync({
+async function css(file: string, is_development: boolean): Promise<string> {
+  const proc = Bun.spawn({
     cmd: [process.execPath, "build", file, "--minify"],
     cwd: import.meta.dir,
     stdio: ["ignore", "pipe", "pipe"],
   });
-  if (!success) throw new Error(stderr.toString("utf-8"));
-  return stdout.toString("utf-8");
+  const [stdoutBuf, stderrBuf] = await Promise.all([
+    new Response(proc.stdout).arrayBuffer(),
+    new Response(proc.stderr).arrayBuffer(),
+  ]);
+  const exitCode = await proc.exited;
+  if (exitCode !== 0) throw new Error(Buffer.from(stderrBuf).toString("utf-8"));
+  return Buffer.from(stdoutBuf).toString("utf-8");
 }
 
 async function run() {
   const devServerZig = readFileSync(join(base_dir, "DevServer.zig"), "utf-8");
   writeIfNotChanged(join(base_dir, "generated.ts"), convertZigEnum(devServerZig, ["IncomingMessageId", "MessageId"]));
 
+  const overlayCSS = await css("../bake/client/overlay.css", !!debug);
+
   const results = await Promise.allSettled(
     ["client", "server", "error"].map(async file => {
       const side = file === "error" ? "client" : file;
@@ -53,7 +60,7 @@ async function run() {
           side: JSON.stringify(side),
           IS_ERROR_RUNTIME: String(file === "error"),
           IS_BUN_DEVELOPMENT: String(!!debug),
-          OVERLAY_CSS: css("../bake/client/overlay.css", !!debug),
+          OVERLAY_CSS: overlayCSS,
         },
         minify: {
           syntax: !debug,
