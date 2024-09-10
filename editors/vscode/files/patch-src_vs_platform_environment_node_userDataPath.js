--- src/vs/platform/environment/node/userDataPath.js.orig	2024-09-04 12:53:09 UTC
+++ src/vs/platform/environment/node/userDataPath.js
@@ -102,7 +102,7 @@
 				case 'darwin':
 					appDataPath = path.join(os.homedir(), 'Library', 'Application Support');
 					break;
-				case 'linux':
+				case 'linux': case 'freebsd':
 					appDataPath = process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 					break;
 				default:
