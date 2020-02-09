--- build/gulpfile.extensions.js.orig	2019-12-10 21:16:00 UTC
+++ build/gulpfile.extensions.js
@@ -162,7 +162,7 @@ const cleanExtensionsBuildTask = task.define('clean-ex
 const compileExtensionsBuildTask = task.define('compile-extensions-build', task.series(
 	cleanExtensionsBuildTask,
 	task.define('bundle-extensions-build', () => ext.packageLocalExtensionsStream().pipe(gulp.dest('.build'))),
-	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream().pipe(gulp.dest('.build'))),
+//	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream().pipe(gulp.dest('.build'))),
 ));
 
 gulp.task(compileExtensionsBuildTask);
