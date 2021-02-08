--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2021-02-03 15:33:23 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -651,7 +651,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
