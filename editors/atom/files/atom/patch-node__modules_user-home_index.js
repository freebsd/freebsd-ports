--- node_modules/user-home/index.js.orig	2019-12-27 06:43:28 UTC
+++ node_modules/user-home/index.js
@@ -7,7 +7,7 @@ if (process.platform === 'win32') {
 	module.exports = env.USERPROFILE || env.HOMEDRIVE + env.HOMEPATH || home || null;
 } else if (process.platform === 'darwin') {
 	module.exports = home || (user ? '/Users/' + user : null) || null;
-} else if (process.platform === 'linux') {
+} else if (process.platform === 'linux' || process.platform === 'freebsd') {
 	module.exports = home ||
 		(user ? (process.getuid() === 0 ? '/root' : '/home/' + user) : null) || null;
 } else {
