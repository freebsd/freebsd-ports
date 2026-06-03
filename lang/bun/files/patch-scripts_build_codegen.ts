-- Skip bun install when node_modules already exists.
-- On FreeBSD, bun install fails due to a linux compat layer limitation
-- with /proc/self/fd (fchdir returns ENOTDIR for symlink-based FDs).
-- By checking for existing node_modules, the build uses pre-populated
-- node_modules from the port's distfile instead.

	2026-04-27 07:19:58 UTC
+++ scripts/build/codegen.ts
@@ -167,7 +167,7 @@ export function registerCodegenRules(n: Ninja, cfg: Co
   n.rule("bun_install", {
     command: hostWin
       ? `cmd /c "cd /d $dir && ${bun} install --frozen-lockfile && ${touch} $stamp"`
-      : `cd $dir && ${bun} install --frozen-lockfile && ${touch} $stamp`,
+      : `cd $dir && ([ -d node_modules ] || ${bun} install --frozen-lockfile) && ${touch} $stamp`,
     description: "install $dir",
     restat: true,
     // bun install can be memory-hungry and grabs a lockfile; serialize.
