Teach OpenCode's CLI build about the FreeBSD opencode-pty daemon.

resolveOpencodePty only embeds a native opencode-pty binary for darwin and
linux, so a FreeBSD build ships without one and the client fails to spawn the
persistent terminal daemon at runtime.  Accept the freebsd platform so the
binary passed via OPENCODE_PTY_BIN is embedded into the executable.

--- packages/cli/script/opencode-pty.ts.orig
+++ packages/cli/script/opencode-pty.ts
@@ -19,7 +19,8 @@
 const pty = createRequire(core.resolve("@opencode-ai/pty/package.json"))
 
 export async function resolveOpencodePty(target: Target): Promise<OpencodePtyAsset | undefined> {
-  if (target.platform !== "darwin" && target.platform !== "linux") return undefined
+  if (target.platform !== "darwin" && target.platform !== "linux" && target.platform !== "freebsd")
+    return undefined
   if (target.arch !== "arm64" && target.arch !== "x64") return undefined
 
   const suffix = [target.platform, target.arch, target.platform === "linux" ? (target.libc ?? "glibc") : undefined]
