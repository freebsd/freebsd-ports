--- packages/app-desktop/ElectronAppWrapper.ts.orig	2026-09-05 19:41:51 UTC
+++ packages/app-desktop/ElectronAppWrapper.ts
@@ -282,7 +282,7 @@ export default class ElectronAppWrapper {
 
 		// Linux icon workaround for bug https://github.com/electron-userland/electron-builder/issues/2098
 		// Fix: https://github.com/electron-userland/electron-builder/issues/2269
-		if (shim.isLinux()) windowOptions.icon = path.join(__dirname, '..', 'build/icons/128x128.png');
+		if (shim.isLinux() || shim.isFreeBSD()) windowOptions.icon = path.join(__dirname, '..', 'build/icons/128x128.png');
 
 		this.win_ = new BrowserWindow(windowOptions);
 
@@ -902,7 +902,7 @@ export default class ElectronAppWrapper {
 		if (this.electronApp().accessibilitySupportEnabled) return;
 
 		const isOrcaRunning = async () => {
-			if (!shim.isLinux()) return false;
+			if (!shim.isLinux() && !shim.isFreeBSD()) return false;
 			try {
 				const matchingProcesses = await execCommand(['ps', '--no-headers', '-C', 'orca'], { quiet: true });
 				return matchingProcesses.trim().length > 0;
