--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2022-08-03 05:14:29 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -666,7 +666,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
