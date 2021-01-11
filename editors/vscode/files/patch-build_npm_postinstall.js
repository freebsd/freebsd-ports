--- build/npm/postinstall.js.orig	2020-07-21 14:27:11 UTC
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
@@ -74,4 +75,4 @@ yarnInstall('test/smoke'); // node modules required fo
 yarnInstall('test/integration/browser'); // node modules required for integration
 yarnInstallBuildDependencies(); // node modules for watching, specific to host node version, not electron
 
-cp.execSync('git config pull.rebase true');
+// cp.execSync('git config pull.rebase true');
