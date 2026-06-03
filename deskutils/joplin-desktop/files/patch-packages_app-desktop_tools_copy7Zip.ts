--- packages/app-desktop/tools/copy7Zip.ts.orig	2024-03-03 08:48:50 UTC
+++ packages/app-desktop/tools/copy7Zip.ts
@@ -21,6 +21,7 @@ const copy7Zip = async () => {
 		'win32': 'win',
 		'darwin': 'mac',
 		'linux': 'linux',
+		'freebsd': 'freebsd',
 	};
 
 	if (!(targetPlatform in platformToSubdirectory)) {
