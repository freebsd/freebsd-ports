diff --git a/packages/hadron-build/commands/release.js b/packages/hadron-build/commands/release.js
index 313ade74a..4c9d67aad 100644
--- a/packages/hadron-build/commands/release.js
+++ b/packages/hadron-build/commands/release.js
@@ -279,7 +279,8 @@ const installDependencies = util.callbackify(async(CONFIG) => {
     cwd: appPackagePath
   };
 
-  await run.async('npm', ['install', '--production'], opts);
+  // await run.async('npm', ['install', '--production'], opts);
+  await run.async('tar', ['xf', process.env.APPMOD], opts);
 
   cli.debug('Production dependencies installed');
 
@@ -302,7 +303,7 @@ const installDependencies = util.callbackify(async(CONFIG) => {
     prebuildTagPrefix: 'totally-not-a-real-prefix-to-force-rebuild'
   };
 
-  await rebuild(rebuildConfig);
+  // await rebuild(rebuildConfig);
 
   // We can not force rebuild mongodb-client-encryption locally, but we need to
   // make sure that the binary is matching the platform we are packaging for and
@@ -310,7 +311,7 @@ const installDependencies = util.callbackify(async(CONFIG) => {
   // is using so that prebuild can download the matching version
   rebuildConfig.prebuildTagPrefix = 'node-v';
   rebuildConfig.onlyModules = ['mongodb-client-encryption'];
-  await rebuild(rebuildConfig);
+  // await rebuild(rebuildConfig);
 
   cli.debug('Native modules rebuilt against Electron.');
 });
