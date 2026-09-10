--- packages/app-desktop/InteropServiceHelper.ts.orig	2026-09-07 07:33:23 UTC
+++ packages/app-desktop/InteropServiceHelper.ts
@@ -67,7 +67,7 @@ export default class InteropServiceHelper {
 			const windowOptions: BrowserWindowConstructorOptions = {
 				// Work around a printing issue: As of Electron 39, if the window is initially hidden, printing crashes the app.
 				// This only seems to be necessary on Linux.
-				show: shim.isLinux(),
+				show: shim.isLinux() || shim.isFreeBSD(),
 			};
 
 			win = bridge().newBrowserWindow(windowOptions);
