--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2021-08-18 23:34:31 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -650,7 +650,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
