--- src/vs/platform/environment/node/userDataPath.ts.orig	2025-06-11 13:47:56 UTC
+++ src/vs/platform/environment/node/userDataPath.ts
@@ -87,6 +87,7 @@ function doGetUserDataPath(cliArgs: NativeParsedArgs, 
 			appDataPath = join(homedir(), 'Library', 'Application Support');
 			break;
 		case 'linux':
+		case 'freebsd':
 			appDataPath = process.env['XDG_CONFIG_HOME'] || join(homedir(), '.config');
 			break;
 		default:
