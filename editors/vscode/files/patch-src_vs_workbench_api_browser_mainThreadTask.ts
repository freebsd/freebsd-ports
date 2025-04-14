--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2025-04-09 23:39:47 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -726,7 +726,7 @@ export class MainThreadTask extends Disposable impleme
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
