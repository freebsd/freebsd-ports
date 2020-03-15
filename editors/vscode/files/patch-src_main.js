--- src/main.js.orig	2020-03-10 09:24:33 UTC
+++ src/main.js
@@ -137,7 +137,7 @@ function configureCommandlineSwitchesSync(cliArgs) {
 		'force-color-profile'
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		SUPPORTED_ELECTRON_SWITCHES.push('force-renderer-accessibility');
 	}
 
