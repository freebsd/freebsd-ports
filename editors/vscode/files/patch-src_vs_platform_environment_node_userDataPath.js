--- src/vs/platform/environment/node/userDataPath.js.orig	2021-05-04 21:42:00 UTC
+++ src/vs/platform/environment/node/userDataPath.js
@@ -80,7 +80,7 @@
 					case 'darwin':
 						appDataPath = path.join(os.homedir(), 'Library', 'Application Support');
 						break;
-					case 'linux':
+					case 'linux': case 'freebsd':
 						appDataPath = process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 						break;
 					default:
