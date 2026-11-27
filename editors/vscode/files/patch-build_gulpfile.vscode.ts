--- build/gulpfile.vscode.ts.orig	2026-11-24 10:26:34 UTC
+++ build/gulpfile.vscode.ts
@@ -223,6 +223,7 @@ function packageTask(platform: string, arch: string, s
 				if (dictationRuntime) {
 					json.dictationRuntime = dictationRuntime;
 				}
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(through(function (file: File.BufferFile) {
