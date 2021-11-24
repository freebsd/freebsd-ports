--- build/gulpfile.vscode.js.orig	2021-11-16 15:42:03 UTC
+++ build/gulpfile.vscode.js
@@ -293,7 +293,7 @@ function packageTask(platform, arch, sourceFolderName,
 			.pipe(util.skipDirectories())
 			.pipe(util.fixWin32DirectoryPermissions())
 			.pipe(filter(['**', '!**/.github/**'], { dot: true })) // https://github.com/microsoft/vscode/issues/116523
-			.pipe(electron(_.extend({}, config, { platform, arch: arch === 'armhf' ? 'arm' : arch, ffmpegChromium: true })))
+			.pipe(electron(_.extend({}, config, { platform, arch: arch === 'armhf' ? 'arm' : arch, ffmpegChromium: false })))
 			.pipe(filter(['**', '!LICENSE', '!LICENSES.chromium.html', '!version'], { dot: true }));
 
 		if (platform === 'linux') {
