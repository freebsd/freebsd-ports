--- build/gulpfile.extensions.ts.orig	2026-10-14 09:52:01 UTC
+++ build/gulpfile.extensions.ts
@@ -274,7 +274,7 @@ export const compileNonNativeExtensionsBuildTask = tas
  * @note this does not clean the directory ahead of it. See {@link cleanExtensionsBuildTask} for that.
  */
 export const compileNonNativeExtensionsBuildTask = task.define('compile-non-native-extensions-build', task.series(
-	bundleMarketplaceExtensionsBuildTask,
+	// bundleMarketplaceExtensionsBuildTask,
 	task.define('bundle-non-native-extensions-build', () => ext.packageNonNativeLocalExtensionsStream(false).pipe(gulp.dest('.build')))
 ));
 task.task(compileNonNativeExtensionsBuildTask);
