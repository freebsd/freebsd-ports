--- src/vs/base/node/userDataPath.js.orig	2021-03-11 08:31:52 UTC
+++ src/vs/base/node/userDataPath.js
@@ -37,7 +37,7 @@
 					case 'darwin':
 						appDataPath = path.join(os.homedir(), 'Library', 'Application Support');
 						break;
-					case 'linux':
+					case 'linux': case 'freebsd':
 						appDataPath = process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 						break;
 					default:
