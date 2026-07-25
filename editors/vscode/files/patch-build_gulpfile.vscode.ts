--- build/gulpfile.vscode.ts.orig	2026-07-22 14:55:04 UTC
+++ build/gulpfile.vscode.ts
@@ -333,6 +333,7 @@ function packageTask(platform: string, arch: string, s
 				if (Object.keys(agentSdks).length > 0) {
 					json.agentSdks = agentSdks;
 				}
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(es.through(function (file) {
