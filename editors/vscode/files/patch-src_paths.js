--- src/paths.js.orig	2020-12-16 14:57:12 UTC
+++ src/paths.js
@@ -34,7 +34,7 @@ function getDefaultUserDataPath() {
 			case 'darwin':
 				appDataPath = path.join(os.homedir(), 'Library', 'Application Support');
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				appDataPath = process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 				break;
 			default:
