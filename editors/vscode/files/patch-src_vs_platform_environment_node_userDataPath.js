--- src/vs/platform/environment/node/userDataPath.js.orig	2024-07-09 12:51:23 UTC
+++ src/vs/platform/environment/node/userDataPath.js
@@ -93,7 +93,7 @@
 				case 'darwin':
 					appDataPath = path.join(os.homedir(), 'Library', 'Application Support');
 					break;
-				case 'linux':
+				case 'linux': case 'freebsd':
 					appDataPath = process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 					break;
 				default:
