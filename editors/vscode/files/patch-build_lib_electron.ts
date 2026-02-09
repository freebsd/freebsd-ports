--- build/lib/electron.ts.orig	2026-02-04 01:55:52 UTC
+++ build/lib/electron.ts
@@ -203,10 +203,11 @@ export const config = {
 	winIcon: 'resources/win32/code.ico',
 	token: process.env['GITHUB_TOKEN'],
 	repo: product.electronRepository || undefined,
-	validateChecksum: true,
+	validateChecksum: false,
 	checksumFile: path.join(root, 'build', 'checksums', 'electron.txt'),
 	createVersionedResources: useVersionedUpdate,
 	productVersionString: versionedResourcesFolder,
+	unsafelyDisableChecksums: true,
 };
 
 function getElectron(arch: string): () => NodeJS.ReadWriteStream {
