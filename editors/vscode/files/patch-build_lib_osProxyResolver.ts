--- build/lib/osProxyResolver.ts.orig	2026-11-10 19:27:51 UTC
+++ build/lib/osProxyResolver.ts
@@ -9,46 +9,47 @@ export const osProxyResolverPlatforms = [
 // The musl variants are never selected as a target, but must be listed so they are excluded from packaging.
 export const osProxyResolverPlatforms = [
 	'darwin-arm64', 'darwin-x64',
+	'freebsd-x64',
 	'linux-arm-gnueabihf', 'linux-arm64-gnu', 'linux-arm64-musl', 'linux-x64-gnu', 'linux-x64-musl',
 	'win32-arm64-msvc', 'win32-x64-msvc',
 ];
 
-function toOSProxyResolverPlatform(platform: string, arch: string): string | undefined {
+function toOSProxyResolverPlatforms(platform: string, arch: string): string[] {
 	switch (platform) {
 		case 'darwin':
-			return arch === 'arm64' || arch === 'x64' ? `darwin-${arch}` : undefined;
+			return arch === 'arm64' || arch === 'x64' ? [`darwin-${arch}`] : [];
 		case 'linux':
 			switch (arch) {
 				case 'arm':
-				case 'armhf': return 'linux-arm-gnueabihf';
-				case 'arm64': return 'linux-arm64-gnu';
-				case 'x64': return 'linux-x64-gnu';
+				case 'armhf': return ['linux-arm-gnueabihf'];
+				case 'arm64': return ['linux-arm64-gnu'];
+				case 'x64': return ['linux-x64-gnu', 'freebsd-x64'];
 			}
-			return undefined;
+			return [];
 		case 'win32':
-			return arch === 'arm64' || arch === 'x64' ? `win32-${arch}-msvc` : undefined;
+			return arch === 'arm64' || arch === 'x64' ? [`win32-${arch}-msvc`] : [];
 	}
-	return undefined;
+	return [];
 }
 
 export function getOSProxyResolverPlatformFiles(platform: string, arch: string, nodeModulesRoot = 'node_modules'): string[] {
-	const target = toOSProxyResolverPlatform(platform, arch);
-	return target ? [path.posix.join(nodeModulesRoot, '@vscode', `os-proxy-resolver-${target}`, '**')] : [];
+	const targets = toOSProxyResolverPlatforms(platform, arch);
+	return targets.map(target => path.posix.join(nodeModulesRoot, '@vscode', `os-proxy-resolver-${target}`, '**'));
 }
 
 export function getOSProxyResolverExcludeFilter(platform: string, arch: string): string[] {
-	const target = toOSProxyResolverPlatform(platform, arch);
+	const targets = toOSProxyResolverPlatforms(platform, arch);
 	return [
 		'**',
 		...osProxyResolverPlatforms
-			.filter(candidate => candidate !== target)
+			.filter(candidate => !targets.includes(candidate))
 			.map(candidate => `!**/node_modules/@vscode/os-proxy-resolver-${candidate}/**`),
 	];
 }
 
 export function ensureOSProxyResolverPlatformPackage(platform: string, arch: string, nodeModulesRoot = 'node_modules', options: EnsureNpmPackageOptions = {}): void {
-	const target = toOSProxyResolverPlatform(platform, arch);
-	if (target) {
+	const targets = toOSProxyResolverPlatforms(platform, arch);
+	for (const target of targets) {
 		ensureNpmPackage(`@vscode/os-proxy-resolver-${target}`, nodeModulesRoot, options);
 	}
 }
