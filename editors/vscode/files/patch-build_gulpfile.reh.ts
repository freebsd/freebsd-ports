--- build/gulpfile.reh.ts.orig	2026-03-06 23:06:10 UTC
+++ build/gulpfile.reh.ts
@@ -27,7 +27,7 @@ import rceditCallback from 'rcedit';
 import glob from 'glob';
 import { promisify } from 'util';
 import rceditCallback from 'rcedit';
-import { compileBuildWithManglingTask } from './gulpfile.compile.ts';
+import { compileBuildWithoutManglingTask } from './gulpfile.compile.ts';
 import { cleanExtensionsBuildTask, compileNonNativeExtensionsBuildTask, compileNativeExtensionsBuildTask, compileExtensionMediaBuildTask } from './gulpfile.extensions.ts';
 import { vscodeWebResourceIncludes, createVSCodeWebFileContentMapper } from './gulpfile.vscode.web.ts';
 import * as cp from 'child_process';
@@ -325,7 +325,7 @@ function packageTask(type: string, platform: string, a
 
 		let productJsonContents = '';
 		const productJsonStream = gulp.src(['product.json'], { base: '.' })
-			.pipe(jsonEditor({ commit, date: readISODate(sourceFolderName), version }))
+			.pipe(jsonEditor({ commit, date: readISODate(sourceFolderName), version, serverDownloadUrlTemplate: 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz' }))
 			.pipe(es.through(function (file) {
 				productJsonContents = file.contents.toString();
 				this.emit('data', file);
@@ -519,7 +519,7 @@ function tweakProductForServerWeb(product: typeof impo
 			gulp.task(serverTaskCI);
 
 			const serverTask = task.define(`vscode-${type}${dashed(platform)}${dashed(arch)}${dashed(minified)}`, task.series(
-				compileBuildWithManglingTask,
+				compileBuildWithoutManglingTask,
 				cleanExtensionsBuildTask,
 				compileNonNativeExtensionsBuildTask,
 				compileExtensionMediaBuildTask,
