--- src/main.js.orig	2020-06-09 17:02:22 UTC
+++ src/main.js
@@ -197,7 +197,7 @@ function configureCommandlineSwitchesSync(cliArgs) {
 		'force-color-profile'
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd') {
 		SUPPORTED_ELECTRON_SWITCHES.push('force-renderer-accessibility');
 	}
 
