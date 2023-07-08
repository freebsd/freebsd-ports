--- src/main.js.orig	2023-07-04 10:23:33 UTC
+++ src/main.js
@@ -139,7 +139,7 @@ if (locale) {
 // Pseudo Language Language Pack is being used.
 // In that case, use `en` as the Electron locale.
 
-if (process.platform === 'win32' || process.platform === 'linux') {
+if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 	const electronLocale = (!locale || locale === 'qps-ploc') ? 'en' : locale;
 	app.commandLine.appendSwitch('lang', electronLocale);
 }
@@ -207,7 +207,7 @@ function configureCommandlineSwitchesSync(cliArgs) {
 		'password-store'
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 
 		// Force enable screen readers on Linux via this flag
 		SUPPORTED_ELECTRON_SWITCHES.push('force-renderer-accessibility');
