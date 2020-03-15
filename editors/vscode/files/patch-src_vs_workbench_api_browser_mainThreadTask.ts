--- src/vs/workbench/api/browser/mainThreadTask.ts.orig	2020-03-09 16:22:02 UTC
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
