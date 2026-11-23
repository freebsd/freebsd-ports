--- build/lib/nodeCompileCache.ts.orig	2026-11-17 02:46:11 UTC
+++ build/lib/nodeCompileCache.ts
@@ -32,7 +32,9 @@ export function shouldGenerateNodeCompileCache(platfor
 		return false;
 	}
 
-	return platform === 'darwin' ? arch === 'arm64' : (platform === 'linux' || platform === 'win32') && arch === 'x64';
+	// return platform === 'darwin' ? arch === 'arm64' : (platform === 'linux' || platform === 'win32') && arch === 'x64';
+	// Attempt to generate node compile cache in poudriere jail fails, disable for now.
+	return false;
 }
 
 export function getNodeCompileCachePaths(platform: string, outputDirectory: string, versionedResourcesFolder: string, product: INodeCompileCacheProduct): INodeCompileCachePaths {
