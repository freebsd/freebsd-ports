--- src/main.js.orig	2022-04-11 07:30:00 UTC
+++ src/main.js
@@ -160,7 +160,7 @@ function configureCommandlineSwitchesSync(cliArgs) {
 		'force-color-profile'
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 
 		// Force enable screen readers on Linux via this flag
 		SUPPORTED_ELECTRON_SWITCHES.push('force-renderer-accessibility');
