--- build/gulpfile.reh.ts.orig	2026-11-24 10:26:34 UTC
+++ build/gulpfile.reh.ts
@@ -336,6 +336,7 @@ function packageTask(type: string, platform: string, a
 						json.agentSdks = agentSdks;
 					}
 				}
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(through(function (file: File.BufferFile) {
