--- src/vs/platform/environment/node/userDataPath.ts.orig	2024-11-05 12:18:19 UTC
+++ src/vs/platform/environment/node/userDataPath.ts
@@ -76,7 +76,7 @@ function doGetUserDataPath(cliArgs: NativeParsedArgs, 
 		case 'darwin':
 			appDataPath = path.join(os.homedir(), 'Library', 'Application Support');
 			break;
-		case 'linux':
+		case 'linux': case 'freebsd':
 			appDataPath = process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 			break;
 		default:
