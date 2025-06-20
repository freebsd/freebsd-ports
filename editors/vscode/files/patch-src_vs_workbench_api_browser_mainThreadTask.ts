--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2025-06-11 13:47:56 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -727,6 +727,7 @@ export class MainThreadTask extends Disposable impleme
 				platform = Platform.Platform.Mac;
 				break;
 			case 'linux':
+			case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
