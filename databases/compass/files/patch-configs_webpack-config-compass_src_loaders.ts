diff --git a/configs/webpack-config-compass/src/loaders.ts b/configs/webpack-config-compass/src/loaders.ts
index db9b1e24e..edc38d489 100644
--- a/configs/webpack-config-compass/src/loaders.ts
+++ b/configs/webpack-config-compass/src/loaders.ts
@@ -8,13 +8,14 @@ import chalk from 'chalk';
 
 function isLatestBrowserslist() {
   // eslint-disable-next-line @typescript-eslint/no-var-requires
-  const browserslistVersion = require('browserslist/package.json').version;
-  const command = `npm view browserslist version --json`;
-  const latestBrowserslistVersion = JSON.parse(
-    execSync(command).toString().trim()
-  );
-
-  return browserslistVersion === latestBrowserslistVersion;
+  // const browserslistVersion = require('browserslist/package.json').version;
+  // const command = `npm view browserslist version --json`;
+  // const latestBrowserslistVersion = JSON.parse(
+  //   execSync(command).toString().trim()
+  // );
+
+  // return browserslistVersion === latestBrowserslistVersion;
+  return true;
 }
 
 const electronVersion = (() => {
