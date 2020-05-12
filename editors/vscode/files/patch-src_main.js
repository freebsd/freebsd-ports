--- src/main.js.orig	2020-05-05 21:48:19 UTC
+++ src/main.js
@@ -143,7 +143,7 @@ function configureCommandlineSwitchesSync(cliArgs) {
 		'force-color-profile'
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		SUPPORTED_ELECTRON_SWITCHES.push('force-renderer-accessibility');
 	}
 
