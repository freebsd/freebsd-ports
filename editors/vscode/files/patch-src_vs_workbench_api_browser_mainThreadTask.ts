--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2022-06-08 11:20:55 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -662,7 +662,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
