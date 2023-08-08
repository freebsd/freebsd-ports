--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2022-11-09 00:04:34 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -667,7 +667,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
