--- build/gulpfile.extensions.js.orig	2022-06-08 11:20:55 UTC
+++ build/gulpfile.extensions.js
@@ -223,7 +223,7 @@ const cleanExtensionsBuildTask = task.define('clean-ex
 const compileExtensionsBuildTask = task.define('compile-extensions-build', task.series(
 	cleanExtensionsBuildTask,
 	task.define('bundle-extensions-build', () => ext.packageLocalExtensionsStream(false).pipe(gulp.dest('.build'))),
-	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false, product.extensionsGallery?.serviceUrl).pipe(gulp.dest('.build'))),
+//	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false, product.extensionsGallery?.serviceUrl).pipe(gulp.dest('.build'))),
 ));
 
 gulp.task(compileExtensionsBuildTask);
