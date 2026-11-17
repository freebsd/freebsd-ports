--- build/lib/copilot.ts.orig	2026-11-16 14:31:01 UTC
+++ build/lib/copilot.ts
@@ -97,6 +97,7 @@ const ripgrepUniversalPlatforms = [
  */
 const ripgrepUniversalPlatforms = [
 	'darwin-arm64', 'darwin-x64',
+	'freebsd-x64',
 	'linux-arm', 'linux-arm64', 'linux-ia32', 'linux-x64',
 	'linux-ppc64', 'linux-riscv64', 'linux-s390x',
 	'win32-arm64', 'win32-ia32', 'win32-x64',
@@ -140,6 +141,16 @@ function toCopilotPackagePlatformArch(platform: string
 	return `${nodePlatform}-${nodeArch}`;
 }
 
+const copilotExtraPlatformArch = 'freebsd-x64';
+
+function getExtraPlatformArchs(platform: string, arch: string): string[] {
+	return toCopilotPackagePlatformArch(platform, arch) === 'linux-x64' ? [copilotExtraPlatformArch] : [];
+}
+
+function getTargetPlatformArchs(target: string, platform: string, arch: string): string[] {
+	return [target, ...getExtraPlatformArchs(platform, arch)];
+}
+
 const copilotOptionalNativePayloadDirs = [
 	'builtin',
 	'builtin-skills',
@@ -167,8 +178,8 @@ export function getRipgrepExcludeFilter(platform: stri
  */
 export function getRipgrepExcludeFilter(platform: string, arch: string): string[] {
 	const { nodePlatform, nodeArch } = toNodePlatformArch(platform, arch);
-	const target = `${nodePlatform}-${nodeArch}`;
-	const nonTargetPlatforms = ripgrepUniversalPlatforms.filter(p => p !== target);
+	const targets = getTargetPlatformArchs(`${nodePlatform}-${nodeArch}`, platform, arch);
+	const nonTargetPlatforms = ripgrepUniversalPlatforms.filter(p => !targets.includes(p));
 
 	const excludes = nonTargetPlatforms.map(p => `!**/node_modules/@vscode/ripgrep-universal/bin/${p}/**`);
 
@@ -296,15 +307,26 @@ export function prepareBuiltInCopilotRipgrepShim(platf
 		throw new Error(`[prepareBuiltInCopilotRipgrepShim] ripgrep source not found at ${ripgrepSource} (build platform=${platform}, arch=${arch}, computed platformArch=${platformArch}). ${diagnostics}`);
 	}
 
-	const ripgrepDest = path.join(copilotSdkBase, 'ripgrep', 'bin', platformArch);
+	const ripgrepTargets: { arch: string; source: string }[] = [{ arch: platformArch, source: ripgrepSource }];
 	const shimMarkerPath = path.join(copilotBase, 'shims.txt');
 
-	try {
-		fs.mkdirSync(ripgrepDest, { recursive: true });
-		fs.cpSync(ripgrepSource, ripgrepDest, { recursive: true });
+	for (const extra of getExtraPlatformArchs(platform, arch)) {
+		const extraSource = path.join(appNodeModulesDir, '@vscode', 'ripgrep-universal', 'bin', extra);
+		if (fs.existsSync(extraSource)) {
+			ripgrepTargets.push({ arch: extra, source: extraSource });
+		} else {
+			console.warn(`[prepareBuiltInCopilotRipgrepShim] ripgrep for ${extra} not found at ${extraSource}; skipping.`);
+		}
+	}
 
+	try {
+		for (const { arch: targetArch, source } of ripgrepTargets) {
+			const ripgrepDest = path.join(copilotSdkBase, 'ripgrep', 'bin', targetArch);
+			fs.mkdirSync(ripgrepDest, { recursive: true });
+			fs.cpSync(source, ripgrepDest, { recursive: true });
+			console.log(`[prepareBuiltInCopilotRipgrepShim] Materialized ripgrep shim for ${targetArch} in ${builtInCopilotExtensionDir}`);
+		}
 		fs.writeFileSync(shimMarkerPath, 'Shims created successfully');
-		console.log(`[prepareBuiltInCopilotRipgrepShim] Materialized ripgrep shim for ${platformArch} in ${builtInCopilotExtensionDir}`);
 	} catch (err) {
 		throw new Error(`[prepareBuiltInCopilotRipgrepShim] Failed to materialize ripgrep shim for ${platformArch}: ${err}`);
 	}
