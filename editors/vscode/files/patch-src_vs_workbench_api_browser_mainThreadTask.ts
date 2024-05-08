--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2024-05-01 01:08:03 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -673,7 +673,7 @@ export class MainThreadTask extends Disposable impleme
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
