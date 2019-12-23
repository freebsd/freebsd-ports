--- build/lib/snapshotLoader.ts.orig	2019-12-18 06:46:04 UTC
+++ build/lib/snapshotLoader.ts
@@ -27,7 +27,7 @@ namespace snaps {
 			break;
 
 		case 'win32':
-		case 'linux':
+		case 'linux': case 'freebsd':
 			loaderFilepath = `VSCode-${process.platform}-${arch}/resources/app/out/vs/loader.js`;
 			startupBlobFilepath = `VSCode-${process.platform}-${arch}/snapshot_blob.bin`;
 			break;
