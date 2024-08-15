diff --git a/packages/hadron-build/lib/target.js b/packages/hadron-build/lib/target.js
index 39ed422ab..7fa409b25 100644
--- a/packages/hadron-build/lib/target.js
+++ b/packages/hadron-build/lib/target.js
@@ -10,7 +10,7 @@ const path = require('path');
 const { promisify } = require('util');
 const normalizePkg = require('normalize-package-data');
 const parseGitHubRepoURL = require('parse-github-repo-url');
-const ffmpegAfterExtract = require('electron-packager-plugin-non-proprietary-codecs-ffmpeg').default;
+// const ffmpegAfterExtract = require('electron-packager-plugin-non-proprietary-codecs-ffmpeg').default;
 const windowsInstallerVersion = require('./windows-installer-version');
 const debug = require('debug')('hadron-build:target');
 const execFile = promisify(childProcess.execFile);
@@ -227,8 +227,11 @@ class Target {
       arch: this.arch,
       electronVersion: this.electronVersion,
       sign: null,
-      afterExtract: [ffmpegAfterExtract]
+      // afterExtract: [ffmpegAfterExtract]
     };
+    if (this.pkg.config.hadron.electronZipDir) {
+      this.packagerOptions.electronZipDir = this.pkg.config.hadron.electronZipDir
+    }
 
     if (this.platform === 'win32') {
       this.configureForWin32();
