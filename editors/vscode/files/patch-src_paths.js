--- src/paths.js.orig	2019-12-10 21:16:00 UTC
+++ src/paths.js
@@ -19,7 +19,8 @@ function getAppDataPath(platform) {
 	switch (platform) {
 		case 'win32': return process.env['VSCODE_APPDATA'] || process.env['APPDATA'] || path.join(process.env['USERPROFILE'], 'AppData', 'Roaming');
 		case 'darwin': return process.env['VSCODE_APPDATA'] || path.join(os.homedir(), 'Library', 'Application Support');
-		case 'linux': return process.env['VSCODE_APPDATA'] || process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
+		case 'linux': case 'freebsd':
+			return process.env['VSCODE_APPDATA'] || process.env['XDG_CONFIG_HOME'] || path.join(os.homedir(), '.config');
 		default: throw new Error('Platform not supported');
 	}
 }
@@ -33,4 +34,4 @@ function getDefaultUserDataPath(platform) {
 }
 
 exports.getAppDataPath = getAppDataPath;
-exports.getDefaultUserDataPath = getDefaultUserDataPath;
\ No newline at end of file
+exports.getDefaultUserDataPath = getDefaultUserDataPath;
