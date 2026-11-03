--- build/gulpfile.extensions.ts.orig	2026-10-27 20:18:03 UTC
+++ build/gulpfile.extensions.ts
@@ -263,7 +263,7 @@ export const compileNonNativeExtensionsBuildTask = tas
  * @note this does not clean the directory ahead of it. See {@link cleanExtensionsBuildTask} for that.
  */
 export const compileNonNativeExtensionsBuildTask = task.define('compile-non-native-extensions-build', task.series(
-	bundleMarketplaceExtensionsBuildTask,
+	// bundleMarketplaceExtensionsBuildTask,
 	task.define('bundle-non-native-extensions-build', () => ext.packageNonNativeLocalExtensionsStream(false).pipe(gulp.dest('.build')))
 ));
 task.task(compileNonNativeExtensionsBuildTask);
