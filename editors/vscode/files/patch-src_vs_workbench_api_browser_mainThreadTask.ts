--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2024-10-31 05:10:14 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -678,7 +678,7 @@ export class MainThreadTask extends Disposable impleme
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
