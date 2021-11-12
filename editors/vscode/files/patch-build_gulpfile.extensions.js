--- build/gulpfile.extensions.js.orig	2021-07-14 21:51:05 UTC
+++ build/gulpfile.extensions.js
@@ -218,7 +218,7 @@ const cleanExtensionsBuildTask = task.define('clean-ex
 const compileExtensionsBuildTask = task.define('compile-extensions-build', task.series(
 	cleanExtensionsBuildTask,
 	task.define('bundle-extensions-build', () => ext.packageLocalExtensionsStream(false).pipe(gulp.dest('.build'))),
-	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false).pipe(gulp.dest('.build'))),
+//	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false).pipe(gulp.dest('.build'))),
 ));
 
 gulp.task(compileExtensionsBuildTask);
