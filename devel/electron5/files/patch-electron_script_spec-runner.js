--- electron/script/spec-runner.js.orig	2019-12-19 06:12:13 UTC
+++ electron/script/spec-runner.js
@@ -40,7 +40,7 @@ function saveSpecHash ([newSpecHash, newSpecInstallHas
 async function runElectronTests () {
   let exe = path.resolve(BASE, utils.getElectronExec())
   const args = process.argv.slice(2)
-  if (process.platform === 'linux') {
+  if (process.platform === 'linux' || process.platform === 'freebsd') {
     args.unshift(path.resolve(__dirname, 'dbus_mock.py'), exe)
     exe = 'python'
   }
