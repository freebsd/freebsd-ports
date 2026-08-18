--- build/gulpfile.vscode.ts.orig	2026-08-11 22:14:08 UTC
+++ build/gulpfile.vscode.ts
@@ -357,6 +357,7 @@ function packageTask(platform: string, arch: string, s
 				if (dictationRuntime) {
 					json.dictationRuntime = dictationRuntime;
 				}
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(es.through(function (file) {
