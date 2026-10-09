--- build/gulpfile.vscode.ts.orig	2026-10-06 08:15:52 UTC
+++ build/gulpfile.vscode.ts
@@ -216,6 +216,7 @@ function packageTask(platform: string, arch: string, s
 				if (dictationRuntime) {
 					json.dictationRuntime = dictationRuntime;
 				}
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(es.through(function (file) {
