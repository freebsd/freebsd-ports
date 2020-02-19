--- script/lib/package-application.js.orig	2019-10-21 17:33:40 UTC
+++ script/lib/package-application.js
@@ -66,7 +66,7 @@ module.exports = function() {
         'Resources'
       );
       setAtomHelperVersion(packagedAppPath);
-    } else if (process.platform === 'linux') {
+    } else if (process.platform === 'linux' || process.platform === 'freebsd') {
       bundledResourcesPath = path.join(packagedAppPath, 'resources');
       chmodNodeFiles(packagedAppPath);
     } else {
@@ -118,7 +118,7 @@ function copyNonASARResources(packagedAppPath, bundled
       path.join(CONFIG.repositoryRootPath, 'resources', 'mac', 'file.icns'),
       path.join(bundledResourcesPath, 'file.icns')
     );
-  } else if (process.platform === 'linux') {
+  } else if (process.platform === 'linux' || process.platform === 'freebsd') {
     fs.copySync(
       path.join(
         CONFIG.repositoryRootPath,
@@ -234,7 +234,7 @@ function renamePackagedAppDir(packageOutputDirPath) {
       path.join(packageOutputDirPath, appBundleName),
       packagedAppPath
     );
-  } else if (process.platform === 'linux') {
+  } else if (process.platform === 'linux' || process.platform === 'freebsd') {
     const appName =
       CONFIG.channel !== 'stable' ? `atom-${CONFIG.channel}` : 'atom';
     let architecture;
