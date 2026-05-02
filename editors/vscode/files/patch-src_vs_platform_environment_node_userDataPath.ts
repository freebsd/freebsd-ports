--- src/vs/platform/environment/node/userDataPath.ts.orig	2026-04-29 14:36:44 UTC
+++ src/vs/platform/environment/node/userDataPath.ts
@@ -101,6 +101,7 @@ export function getDefaultUserDataPath(productName: st
 			appDataPath = join(homedir(), 'Library', 'Application Support');
 			break;
 		case 'linux':
+		case 'freebsd':
 			appDataPath = process.env['XDG_CONFIG_HOME'] || join(homedir(), '.config');
 			break;
 		default:
