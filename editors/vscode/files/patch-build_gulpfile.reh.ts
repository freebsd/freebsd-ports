--- build/gulpfile.reh.ts.orig	2025-12-14 06:38:54 UTC
+++ build/gulpfile.reh.ts
@@ -25,7 +25,7 @@ import glob from 'glob';
 import File from 'vinyl';
 import * as fs from 'fs';
 import glob from 'glob';
-import { compileBuildWithManglingTask } from './gulpfile.compile.ts';
+import { compileBuildWithoutManglingTask } from './gulpfile.compile.ts';
 import { cleanExtensionsBuildTask, compileNonNativeExtensionsBuildTask, compileNativeExtensionsBuildTask, compileExtensionMediaBuildTask } from './gulpfile.extensions.ts';
 import { vscodeWebResourceIncludes, createVSCodeWebFileContentMapper } from './gulpfile.vscode.web.ts';
 import * as cp from 'child_process';
@@ -321,7 +321,7 @@ function packageTask(type: string, platform: string, a
 
 		let productJsonContents = '';
 		const productJsonStream = gulp.src(['product.json'], { base: '.' })
-			.pipe(jsonEditor({ commit, date: readISODate('out-build'), version }))
+			.pipe(jsonEditor({ commit, date: readISODate('out-build'), version, serverDownloadUrlTemplate: 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz' }))
 			.pipe(es.through(function (file) {
 				productJsonContents = file.contents.toString();
 				this.emit('data', file);
@@ -475,7 +475,7 @@ function tweakProductForServerWeb(product: typeof impo
 			gulp.task(serverTaskCI);
 
 			const serverTask = task.define(`vscode-${type}${dashed(platform)}${dashed(arch)}${dashed(minified)}`, task.series(
-				compileBuildWithManglingTask,
+				compileBuildWithoutManglingTask,
 				cleanExtensionsBuildTask,
 				compileNonNativeExtensionsBuildTask,
 				compileExtensionMediaBuildTask,
