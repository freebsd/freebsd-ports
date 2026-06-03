--- build/gulpfile.vscode.ts.orig	2026-05-29 07:25:37 UTC
+++ build/gulpfile.vscode.ts
@@ -304,6 +304,7 @@ function packageTask(platform: string, arch: string, s
 				json.date = readISODate(out);
 				json.checksums = checksums;
 				json.version = version;
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(es.through(function (file) {
