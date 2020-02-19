--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2020-02-05 19:39:53 UTC
+++ src/vs/workbench/api/browser/mainThreadTask.ts
@@ -592,7 +592,7 @@ export class MainThreadTask implements MainThreadTaskS
 			case 'darwin':
 				platform = Platform.Platform.Mac;
 				break;
-			case 'linux':
+			case 'linux': case 'freebsd':
 				platform = Platform.Platform.Linux;
 				break;
 			default:
