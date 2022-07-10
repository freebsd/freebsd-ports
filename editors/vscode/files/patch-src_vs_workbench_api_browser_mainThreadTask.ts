--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2022-07-05 18:15:23 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -663,7 +663,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
