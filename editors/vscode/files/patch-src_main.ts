--- src/main.ts.orig	2024-10-31 05:10:14 UTC
+++ src/main.ts
@@ -141,7 +141,7 @@ if (userLocale) {
 // Pseudo Language Language Pack is being used.
 // In that case, use `en` as the Electron locale.
 
-if (process.platform === 'win32' || process.platform === 'linux') {
+if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 	const electronLocale = (!userLocale || userLocale === 'qps-ploc') ? 'en' : userLocale;
 	app.commandLine.appendSwitch('lang', electronLocale);
 }
@@ -206,7 +206,7 @@ function configureCommandlineSwitchesSync(cliArgs: Nat
 		'proxy-bypass-list'
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 
 		// Force enable screen readers on Linux via this flag
 		SUPPORTED_ELECTRON_SWITCHES.push('force-renderer-accessibility');
