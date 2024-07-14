--- src/main.js.orig	2024-07-09 12:51:23 UTC
+++ src/main.js
@@ -140,7 +140,7 @@ if (locale) {
 // Pseudo Language Language Pack is being used.
 // In that case, use `en` as the Electron locale.
 
-if (process.platform === 'win32' || process.platform === 'linux') {
+if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd') {
 	const electronLocale = (!locale || locale === 'qps-ploc') ? 'en' : locale;
 	app.commandLine.appendSwitch('lang', electronLocale);
 }
@@ -211,7 +211,7 @@ function configureCommandlineSwitchesSync(cliArgs) {
 		'proxy-bypass-list'
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		// Force enable screen readers on Linux via this flag
 		SUPPORTED_ELECTRON_SWITCHES.push('force-renderer-accessibility');
 
