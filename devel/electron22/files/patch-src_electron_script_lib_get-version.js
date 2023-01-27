--- electron/script/lib/get-version.js.orig	2023-01-20 15:13:09.374140000 +0100
+++ electron/script/lib/get-version.js	2023-01-20 15:13:35.153332000 +0100
@@ -11,12 +11,6 @@ module.exports.getElectronVersion = () => {
   // The only difference in the "git describe" technique is that technically a commit can "change" it's version
   // number if a tag is created / removed retroactively.  i.e. the first time a commit is pushed it will be 1.2.3
   // and after the tag is made rebuilding the same commit will result in it being 1.2.4
-  const output = spawnSync('git', ['describe', '--tags', '--abbrev=0'], {
-    cwd: path.resolve(__dirname, '..', '..')
-  });
-  if (output.status !== 0) {
-    console.error(output.stderr);
-    throw new Error('Failed to get current electron version');
-  }
-  return output.stdout.toString().trim().replace(/^v/g, '');
+  const output = "22.0.1";
+  return output.toString().trim().replace(/^v/g, '');
 };
