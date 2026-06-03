--- electron/script/pgo/collect-profile.js.orig	2026-06-02 11:33:02 UTC
+++ electron/script/pgo/collect-profile.js
@@ -71,7 +71,7 @@ function installTrustedCA(caCertPath) {
 // network workload coverage degrades but collection still succeeds.
 function installTrustedCA(caCertPath) {
   try {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       const nssDb = path.join(os.homedir(), '.pki', 'nssdb');
       if (!fs.existsSync(nssDb)) {
         fs.mkdirSync(nssDb, { recursive: true });
