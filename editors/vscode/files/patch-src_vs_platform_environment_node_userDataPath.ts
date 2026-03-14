--- src/vs/platform/environment/node/userDataPath.ts.orig	2026-03-06 23:06:10 UTC
+++ src/vs/platform/environment/node/userDataPath.ts
@@ -91,6 +91,7 @@ function doGetUserDataPath(cliArgs: NativeParsedArgs, 
 			appDataPath = join(homedir(), 'Library', 'Application Support');
 			break;
 		case 'linux':
+		case 'freebsd':
 			appDataPath = process.env['XDG_CONFIG_HOME'] || join(homedir(), '.config');
 			break;
 		default:
