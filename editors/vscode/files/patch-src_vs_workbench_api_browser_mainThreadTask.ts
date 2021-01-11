--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2020-08-25 09:40:01 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -622,7 +622,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
