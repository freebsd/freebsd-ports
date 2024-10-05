--- src/vs/platform/environment/node/userDataPath.js.orig	2024-09-27 21:08:28 UTC
+++ src/vs/platform/environment/node/userDataPath.js
@@ -108,7 +108,7 @@ const module = { exports: {} };
 				case 'darwin':
 					appDataPath = path.join(os.homedir(), 'Library', 'Application Support');
 					break;
-				case 'linux':
+				case 'linux': case 'freebsd':
 					appDataPath = process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 					break;
 				default:
