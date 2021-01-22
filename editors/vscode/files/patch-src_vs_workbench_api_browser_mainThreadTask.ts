--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2020-11-10 22:57:26 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -645,7 +645,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
