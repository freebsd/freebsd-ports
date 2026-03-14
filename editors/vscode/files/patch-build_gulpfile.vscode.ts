--- build/gulpfile.vscode.ts.orig	2026-03-06 23:06:10 UTC
+++ build/gulpfile.vscode.ts
@@ -382,7 +382,7 @@ function packageTask(platform: string, arch: string, s
 
 		let productJsonContents: string;
 		const productJsonStream = gulp.src(['product.json'], { base: '.' })
-			.pipe(jsonEditor({ commit, date: readISODate(out), checksums, version }))
+			.pipe(jsonEditor({ commit, date: readISODate(out), checksums, version, serverDownloadUrlTemplate: 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz' }))
 			.pipe(es.through(function (file) {
 				productJsonContents = file.contents.toString();
 				this.emit('data', file);
