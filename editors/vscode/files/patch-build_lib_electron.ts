--- build/lib/electron.ts.orig	2026-03-06 23:06:10 UTC
+++ build/lib/electron.ts
@@ -204,10 +204,11 @@ export const config = {
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
