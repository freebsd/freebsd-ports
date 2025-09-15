--- build/gulpfile.extensions.js.orig	2025-09-09 22:02:15 UTC
+++ build/gulpfile.extensions.js
@@ -235,7 +235,7 @@ const compileNonNativeExtensionsBuildTask = task.defin
  * @note this does not clean the directory ahead of it. See {@link cleanExtensionsBuildTask} for that.
  */
 const compileNonNativeExtensionsBuildTask = task.define('compile-non-native-extensions-build', task.series(
-	bundleMarketplaceExtensionsBuildTask,
+	// bundleMarketplaceExtensionsBuildTask,
 	task.define('bundle-non-native-extensions-build', () => ext.packageNonNativeLocalExtensionsStream(false, false).pipe(gulp.dest('.build')))
 ));
 gulp.task(compileNonNativeExtensionsBuildTask);
