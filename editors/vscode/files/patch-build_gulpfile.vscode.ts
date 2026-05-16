--- build/gulpfile.vscode.ts.orig	2026-05-12 20:17:22 UTC
+++ build/gulpfile.vscode.ts
@@ -307,6 +307,7 @@ function packageTask(platform: string, arch: string, s
 				json.date = readISODate(out);
 				json.checksums = checksums;
 				json.version = version;
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(es.through(function (file) {
