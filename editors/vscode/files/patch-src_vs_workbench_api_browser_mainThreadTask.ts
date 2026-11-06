--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2026-11-05 17:50:22 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -766,6 +766,7 @@ export class MainThreadTask extends Disposable impleme
 				platform = Platform.Platform.Mac;
 				break;
 			case 'linux':
+			case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
