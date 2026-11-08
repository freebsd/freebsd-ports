--- build/gulpfile.reh.ts.orig	2026-09-30 08:38:38 UTC
+++ build/gulpfile.reh.ts
@@ -341,6 +341,7 @@ function packageTask(type: string, platform: string, a
 						json.agentSdks = agentSdks;
 					}
 				}
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(es.through(function (file) {
