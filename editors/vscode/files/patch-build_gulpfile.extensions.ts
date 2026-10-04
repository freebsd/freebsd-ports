--- build/gulpfile.extensions.ts.orig	2026-09-30 08:38:38 UTC
+++ build/gulpfile.extensions.ts
@@ -271,7 +271,7 @@ export const compileNonNativeExtensionsBuildTask = tas
  * @note this does not clean the directory ahead of it. See {@link cleanExtensionsBuildTask} for that.
  */
 export const compileNonNativeExtensionsBuildTask = task.define('compile-non-native-extensions-build', task.series(
-	bundleMarketplaceExtensionsBuildTask,
+	// bundleMarketplaceExtensionsBuildTask,
 	task.define('bundle-non-native-extensions-build', () => ext.packageNonNativeLocalExtensionsStream(false).pipe(gulp.dest('.build')))
 ));
 task.task(compileNonNativeExtensionsBuildTask);
