--- src/vs/platform/environment/node/userDataPath.js.orig	2021-08-18 23:34:31 UTC
+++ src/vs/platform/environment/node/userDataPath.js
@@ -85,7 +85,7 @@
 				case 'darwin':
 					appDataPath = path.join(os.homedir(), 'Library', 'Application Support');
 					break;
-				case 'linux':
+				case 'linux': case 'freebsd':
 					appDataPath = process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 					break;
 				default:
