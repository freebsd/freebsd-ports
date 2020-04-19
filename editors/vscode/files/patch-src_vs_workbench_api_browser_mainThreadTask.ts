--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2020-04-16 15:59:11 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -593,7 +593,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
