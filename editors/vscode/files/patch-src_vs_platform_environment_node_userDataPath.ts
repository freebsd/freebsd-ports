--- src/vs/platform/environment/node/userDataPath.ts.orig	2026-05-12 20:17:22 UTC
+++ src/vs/platform/environment/node/userDataPath.ts
@@ -96,6 +96,7 @@ export function getDefaultUserDataPath(productName: st
 			appDataPath = join(homedir(), 'Library', 'Application Support');
 			break;
 		case 'linux':
+		case 'freebsd':
 			appDataPath = process.env['XDG_CONFIG_HOME'] || join(homedir(), '.config');
 			break;
 		default:
