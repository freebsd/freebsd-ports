--- build/gulpfile.vscode.js.orig	2019-12-31 07:38:33 UTC
+++ build/gulpfile.vscode.js
@@ -269,7 +269,7 @@ function packageTask(platform, arch, sourceFolderName,
 		let result = all
 			.pipe(util.skipDirectories())
 			.pipe(util.fixWin32DirectoryPermissions())
-			.pipe(electron(_.extend({}, config, { platform, arch, ffmpegChromium: true })))
+			.pipe(electron(_.extend({}, config, { platform, arch, ffmpegChromium: false })))
 			.pipe(filter(['**', '!LICENSE', '!LICENSES.chromium.html', '!version'], { dot: true }));
 
 		if (platform === 'linux') {
