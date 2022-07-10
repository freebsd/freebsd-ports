--- build/lib/snapshotLoader.ts.orig	2022-07-05 18:15:23 UTC
+++ build/lib/snapshotLoader.ts
@@ -25,7 +25,7 @@ namespace snaps {
 			break;
 
 		case 'win32':
-		case 'linux':
+		case 'linux': case 'freebsd':
 			loaderFilepath = `VSCode-${process.platform}-${arch}/resources/app/out/vs/loader.js`;
 			startupBlobFilepath = `VSCode-${process.platform}-${arch}/snapshot_blob.bin`;
 			break;
