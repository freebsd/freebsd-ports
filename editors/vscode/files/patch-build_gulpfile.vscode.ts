--- build/gulpfile.vscode.ts.orig	2026-05-05 18:23:50 UTC
+++ build/gulpfile.vscode.ts
@@ -317,6 +317,7 @@ function packageTask(platform: string, arch: string, s
 					const embeddedObj = json['embedded'] as EmbeddedProductInfo;
 					embeddedObj['darwinSiblingBundleIdentifier'] = json['darwinBundleIdentifier'] as string;
 				}
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(es.through(function (file) {
