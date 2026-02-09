--- build/gulpfile.vscode.ts.orig	2026-02-04 01:55:52 UTC
+++ build/gulpfile.vscode.ts
@@ -271,7 +271,7 @@ function packageTask(platform: string, arch: string, s
 
 		let productJsonContents: string;
 		const productJsonStream = gulp.src(['product.json'], { base: '.' })
-			.pipe(jsonEditor({ commit, date: readISODate('out-build'), checksums, version }))
+			.pipe(jsonEditor({ commit, date: readISODate('out-build'), checksums, version, serverDownloadUrlTemplate: 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz' }))
 			.pipe(es.through(function (file) {
 				productJsonContents = file.contents.toString();
 				this.emit('data', file);
