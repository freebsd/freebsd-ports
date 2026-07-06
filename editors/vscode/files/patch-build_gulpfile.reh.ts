--- build/gulpfile.reh.ts.orig	2026-06-30 11:53:00 UTC
+++ build/gulpfile.reh.ts
@@ -22,7 +22,7 @@ import rceditCallback from 'rcedit';
 import glob from 'glob';
 import { promisify } from 'util';
 import rceditCallback from 'rcedit';
-import { compileBuildWithManglingTask } from './gulpfile.compile.ts';
+import { compileBuildWithoutManglingTask } from './gulpfile.compile.ts';
 import { cleanExtensionsBuildTask, compileNonNativeExtensionsBuildTask, compileNativeExtensionsBuildTask, compileExtensionMediaBuildTask, compileCopilotExtensionBuildTask } from './gulpfile.extensions.ts';
 import { vscodeWebResourceIncludes, createVSCodeWebFileContentMapper } from './gulpfile.vscode.web.ts';
 import * as cp from 'child_process';
@@ -424,6 +424,7 @@ function packageTask(type: string, platform: string, a
 						json.agentSdks = agentSdks;
 					}
 				}
+				json.serverDownloadUrlTemplate = 'https://github.com/tagattie/FreeBSD-VSCode/releases/download/%%DISTVERSION%%/vscode-reh-${os}-${arch}-%%DISTVERSION%%.tar.gz';
 				return json;
 			}))
 			.pipe(es.through(function (file) {
@@ -671,7 +672,7 @@ function tweakProductForServerWeb(product: typeof impo
 			task.task(serverTaskCI);
 
 			const serverTask = task.define(`vscode-${type}${dashed(platform)}${dashed(arch)}${dashed(minified)}`, task.series(
-				compileBuildWithManglingTask,
+				compileBuildWithoutManglingTask,
 				cleanExtensionsBuildTask,
 				compileNonNativeExtensionsBuildTask,
 				compileCopilotExtensionBuildTask,
