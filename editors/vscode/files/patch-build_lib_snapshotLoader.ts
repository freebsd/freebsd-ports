--- build/lib/snapshotLoader.ts.orig	2025-06-11 13:47:56 UTC
+++ build/lib/snapshotLoader.ts
@@ -26,6 +26,7 @@ export namespace snaps {
 
 		case 'win32':
 		case 'linux':
+		case 'freebsd':
 			loaderFilepath = `VSCode-${process.platform}-${arch}/resources/app/out/vs/loader.js`;
 			startupBlobFilepath = `VSCode-${process.platform}-${arch}/snapshot_blob.bin`;
 			break;
