--- build/gulpfile.reh.ts.orig	2026-11-10 19:27:51 UTC
+++ build/gulpfile.reh.ts
@@ -335,6 +335,7 @@ function packageTask(type: string, platform: string, a
 						json.agentSdks = agentSdks;
 					}
 				}
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(es.through(function (file) {
