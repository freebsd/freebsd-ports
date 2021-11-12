--- build/npm/postinstall.js.orig	2021-07-14 21:51:05 UTC
+++ build/npm/postinstall.js
@@ -21,8 +21,9 @@ function yarnInstall(location, opts) {
 	const raw = process.env['npm_config_argv'] || '{}';
 	const argv = JSON.parse(raw);
 	const original = argv.original || [];
-	const args = original.filter(arg => arg === '--ignore-optional' || arg === '--frozen-lockfile');
-	if (opts.ignoreEngines) {
+	const passargs = ['--ignore-optional', '--frozen-lockfile', '--offline', '--no-progress', '--verbose'];
+	const args = original.filter(arg => passargs.includes(arg));
+ 	if (opts.ignoreEngines) {
 		args.push('--ignore-engines');
 		delete opts.ignoreEngines;
 	}
@@ -88,4 +89,4 @@ runtime "${runtime}"`;
 	yarnInstall(watchPath);
 }
 
-cp.execSync('git config pull.rebase merges');
+// cp.execSync('git config pull.rebase true');
