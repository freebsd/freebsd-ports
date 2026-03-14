--- build/gulpfile.extensions.ts.orig	2026-03-06 23:06:10 UTC
+++ build/gulpfile.extensions.ts
@@ -267,7 +267,7 @@ export const compileNonNativeExtensionsBuildTask = tas
  * @note this does not clean the directory ahead of it. See {@link cleanExtensionsBuildTask} for that.
  */
 export const compileNonNativeExtensionsBuildTask = task.define('compile-non-native-extensions-build', task.series(
-	bundleMarketplaceExtensionsBuildTask,
+	// bundleMarketplaceExtensionsBuildTask,
 	task.define('bundle-non-native-extensions-build', () => ext.packageNonNativeLocalExtensionsStream(false, false).pipe(gulp.dest('.build')))
 ));
 gulp.task(compileNonNativeExtensionsBuildTask);
