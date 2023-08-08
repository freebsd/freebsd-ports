--- src/vs/platform/environment/node/userDataPath.js.orig	2022-10-12 10:08:52 UTC
+++ src/vs/platform/environment/node/userDataPath.js
@@ -91,7 +91,7 @@
 				case 'darwin':
 					appDataPath = path.join(os.homedir(), 'Library', 'Application Support');
 					break;
-				case 'linux':
+				case 'linux': case 'freebsd':
 					appDataPath = process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 					break;
 				default:
