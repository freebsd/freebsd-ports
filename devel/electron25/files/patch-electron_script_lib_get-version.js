--- electron/script/lib/get-version.js.orig	2023-01-24 16:58:16 UTC
+++ electron/script/lib/get-version.js
@@ -11,12 +11,10 @@ module.exports.getElectronVersion = () => {
   // The only difference in the "git describe" technique is that technically a commit can "change" it's version
   // number if a tag is created / removed retroactively.  i.e. the first time a commit is pushed it will be 1.2.3
   // and after the tag is made rebuilding the same commit will result in it being 1.2.4
-  const output = spawnSync('git', ['describe', '--tags', '--abbrev=0'], {
-    cwd: path.resolve(__dirname, '..', '..')
-  });
+  const output = spawnSync('basename', [path.resolve(__dirname, '..', '..', '..', '..')]);
   if (output.status !== 0) {
     console.error(output.stderr);
     throw new Error('Failed to get current electron version');
   }
-  return output.stdout.toString().trim().replace(/^v/g, '');
+  return output.stdout.toString().trim().replace(/^electron-/g, '');
 };
