--- src/crash-reporter-start.js.orig	2019-10-21 17:33:40 UTC
+++ src/crash-reporter-start.js
@@ -1,15 +1,2 @@
 module.exports = function(params) {
-  const { crashReporter } = require('electron');
-  const os = require('os');
-  const platformRelease = os.release();
-  const arch = os.arch();
-  const { uploadToServer, releaseChannel } = params;
-
-  crashReporter.start({
-    productName: 'Atom',
-    companyName: 'GitHub',
-    submitURL: 'https://atom.io/crash_reports',
-    uploadToServer,
-    extra: { platformRelease, arch, releaseChannel }
-  });
 };
