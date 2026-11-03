--- src/mainImpl.ts.orig	2026-10-27 20:18:03 UTC
+++ src/mainImpl.ts
@@ -67,7 +67,7 @@ perf.mark('code/didGetUserDataPath');
 app.setPath('userData', userDataPath);
 perf.mark('code/didGetUserDataPath');
 
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd') {
 	const snapName = process.env['SNAP_INSTANCE_NAME'];
 	const installedDesktopName = product.linuxDesktopName && `/usr/share/applications/${product.linuxDesktopName}.desktop`;
 	if (snapName) {
@@ -168,7 +168,7 @@ if (userLocale) {
 // Pseudo Language Language Pack is being used.
 // In that case, use `en` as the Electron locale.
 
-if (process.platform === 'win32' || process.platform === 'linux') {
+if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 	const electronLocale = (!userLocale || userLocale === 'qps-ploc') ? 'en' : userLocale;
 	app.commandLine.appendSwitch('lang', electronLocale);
 }
@@ -266,7 +266,7 @@ function configureCommandlineSwitchesSync(cliArgs: Nat
 		'remote-debugging-port'
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 
 		// Force enable screen readers on Linux via this flag
 		SUPPORTED_ELECTRON_SWITCHES.push('force-renderer-accessibility');
@@ -363,7 +363,7 @@ function configureCommandlineSwitchesSync(cliArgs: Nat
 	// `GlobalShortcutsPortal` - Enables Electron's `globalShortcut` (system-wide keybindings) on Linux Wayland via the XDG global shortcuts portal (no-op elsewhere)
 	// `UpdateCompositorMemoryPolicyOnScreenChange` - Recompute the compositor memory budget on display changes (https://chromium-review.googlesource.com/c/chromium/src/+/8594621)
 	const featuresToEnable =
-		`NetAdapterMaxBufSizeFeature:NetAdapterMaxBufSize/8192,DocumentPolicyIncludeJSCallStacksInCrashReports,EarlyEstablishGpuChannel,EstablishGpuChannelAsync,UpdateCompositorMemoryPolicyOnScreenChange${process.platform === 'linux' ? ',GlobalShortcutsPortal' : ''},${app.commandLine.getSwitchValue('enable-features')}`;
+		`NetAdapterMaxBufSizeFeature:NetAdapterMaxBufSize/8192,DocumentPolicyIncludeJSCallStacksInCrashReports,EarlyEstablishGpuChannel,EstablishGpuChannelAsync,UpdateCompositorMemoryPolicyOnScreenChange${(process.platform === 'linux' || process.platform === 'freebsd') ? ',GlobalShortcutsPortal' : ''},${app.commandLine.getSwitchValue('enable-features')}`;
 	app.commandLine.appendSwitch('enable-features', featuresToEnable);
 
 	// Following features are disabled from the runtime:
