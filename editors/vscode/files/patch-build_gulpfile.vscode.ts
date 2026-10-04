--- build/gulpfile.vscode.ts.orig	2026-09-30 08:38:38 UTC
+++ build/gulpfile.vscode.ts
@@ -222,6 +222,7 @@ function packageTask(platform: string, arch: string, s
 				if (dictationRuntime) {
 					json.dictationRuntime = dictationRuntime;
 				}
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(es.through(function (file) {
