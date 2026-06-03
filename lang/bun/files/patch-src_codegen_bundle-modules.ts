-- Replace Bun.spawnSync with async Bun.spawn in bundle-modules.
-- On FreeBSD linux compat layer, Bun.spawnSync with stdio:"pipe" fails
-- with EINVAL because pread() is not valid on pipes. Using async Bun.spawn
-- with Response.arrayBuffer() works correctly on FreeBSD linux compat.

	2026-04-27 07:15:02 UTC
+++ src/codegen/bundle-modules.ts
@@ -221,12 +221,22 @@ verbose("running: ", config_cli);
   path.join(TMP_DIR, "modules_out"),
 ];
 verbose("running: ", config_cli);
-const out = Bun.spawnSync({
+const _spawnProc = Bun.spawn({
   cmd: config_cli,
   cwd: process.cwd(),
   env: process.env,
-  stdio: ["pipe", "pipe", "pipe"],
+  stdio: ["ignore", "pipe", "pipe"],
 });
+const [_spawnStdout, _spawnStderr] = await Promise.all([
+  new Response(_spawnProc.stdout).arrayBuffer(),
+  new Response(_spawnProc.stderr).arrayBuffer(),
+]);
+const _spawnExit = await _spawnProc.exited;
+const out = {
+  exitCode: _spawnExit,
+  stdout: Buffer.from(_spawnStdout),
+  stderr: Buffer.from(_spawnStderr),
+};
 if (out.exitCode !== 0) {
   console.error(out.stderr.toString());
   process.exit(out.exitCode);
