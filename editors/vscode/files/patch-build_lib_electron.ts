--- build/lib/electron.ts.orig	2026-11-10 19:27:51 UTC
+++ build/lib/electron.ts
@@ -254,10 +254,11 @@ export const config = {
 	winIcon: 'resources/win32/code.ico',
 	token: process.env['GITHUB_TOKEN'],
 	repo: electronAssetResolver,
-	validateChecksum: true,
+	validateChecksum: false,
 	checksumFile: electronChecksumFile,
 	createVersionedResources: useVersionedUpdate,
 	productVersionString: versionedResourcesFolder,
+	unsafelyDisableChecksums: true,
 };
 
 function getElectron(arch: string): () => NodeJS.ReadWriteStream {
