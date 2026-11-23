--- extensions/copilot/script/postinstall.ts.orig	2026-11-22 07:55:26 UTC
+++ extensions/copilot/script/postinstall.ts
@@ -96,7 +96,7 @@ function getCopilotPlatformPackageCandidates(): string
 function getCopilotPlatformPackageCandidates(): string[] {
 	const arch = process.arch;
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		const linuxCandidates = [`linux-${arch}`, `linuxmusl-${arch}`];
 		return isLinuxMuslRuntime() ? linuxCandidates.reverse() : linuxCandidates;
 	}
