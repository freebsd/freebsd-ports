--- build/npm/postinstall.js.orig	2024-07-31 20:26:36 UTC
+++ build/npm/postinstall.js
@@ -42,8 +42,14 @@ function yarnInstall(dir, opts) {
 	const raw = process.env['npm_config_argv'] || '{}';
 	const argv = JSON.parse(raw);
 	const original = argv.original || [];
-	const args = original.filter(arg => arg === '--ignore-optional' || arg === '--frozen-lockfile' || arg === '--check-files');
-
+	const passargs = ['--ignore-optional', '--frozen-lockfile', '--check-files',
+			'--ignore-scripts', '--offline', '--no-progress', '--verbose'];
+	const args = original.filter(arg => passargs.includes(arg));
+	if (opts.cwd === 'remote') {
+		args.push('--use-yarnrc=' + process.env.PWD + '/' + opts.cwd + '/.yarnrc');
+	} else {
+		args.push('--use-yarnrc=' + process.env.PWD + '/.yarnrc');
+	}
 	if (opts.ignoreEngines) {
 		args.push('--ignore-engines');
 		delete opts.ignoreEngines;
@@ -128,5 +134,5 @@ for (let dir of dirs) {
 	yarnInstall(dir, opts);
 }
 
-cp.execSync('git config pull.rebase merges');
-cp.execSync('git config blame.ignoreRevsFile .git-blame-ignore-revs');
+// cp.execSync('git config pull.rebase merges');
+// cp.execSync('git config blame.ignoreRevsFile .git-blame-ignore-revs');
