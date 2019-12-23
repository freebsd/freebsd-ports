--- build/npm/postinstall.js.orig	2019-11-13 16:23:28 UTC
+++ build/npm/postinstall.js
@@ -20,7 +20,8 @@ function yarnInstall(location, opts) {
 	const raw = process.env['npm_config_argv'] || '{}';
 	const argv = JSON.parse(raw);
 	const original = argv.original || [];
-	const args = original.filter(arg => arg === '--ignore-optional' || arg === '--frozen-lockfile');
+	const passargs = ['--ignore-optional', '--frozen-lockfile', '--offline', '--no-progress', '--verbose'];
+	const args = original.filter(arg => passargs.includes(arg));
 
 	console.log(`Installing dependencies in ${location}...`);
 	console.log(`$ yarn ${args.join(' ')}`);
