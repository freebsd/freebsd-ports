--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2023-10-03 13:06:11 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -671,7 +671,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
