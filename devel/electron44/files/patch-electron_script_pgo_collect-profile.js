--- electron/script/pgo/collect-profile.js.orig	2026-06-09 06:05:33 UTC
+++ electron/script/pgo/collect-profile.js
@@ -75,7 +75,7 @@ function installTrustedCA(caCertPath) {
 // network workload coverage degrades but collection still succeeds.
 function installTrustedCA(caCertPath) {
   try {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       const nssDb = path.join(os.homedir(), '.pki', 'nssdb');
       if (!fs.existsSync(nssDb)) {
         fs.mkdirSync(nssDb, { recursive: true });
