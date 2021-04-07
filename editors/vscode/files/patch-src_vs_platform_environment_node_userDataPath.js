--- src/vs/platform/environment/node/userDataPath.js.orig	2021-04-06 08:07:24 UTC
+++ src/vs/platform/environment/node/userDataPath.js
@@ -64,7 +64,7 @@
 					case 'darwin':
 						appDataPath = path.join(os.homedir(), 'Library', 'Application Support');
 						break;
-					case 'linux':
+					case 'linux': case 'freebsd':
 						appDataPath = process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 						break;
 					default:
