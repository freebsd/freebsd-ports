--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2019-12-10 21:16:00 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -588,7 +588,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
