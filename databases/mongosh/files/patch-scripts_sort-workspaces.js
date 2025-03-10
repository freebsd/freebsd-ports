--- scripts/sort-workspaces.js.orig	2024-05-03 16:42:16 UTC
+++ scripts/sort-workspaces.js
@@ -22,7 +22,7 @@ async function main() {
   ));
 
   // should use the scopes in lerna.json
-  const { stdout } = await exec('npx -y lerna ls --all --no-since --toposort --json');
+  const { stdout } = await exec('npx -y lerna ls --all --toposort --json');
   packageJSON.workspaces = JSON.parse(stdout).map(({ location }) => path.relative(monorepoRoot, location));
 
   await fs.writeFile(
