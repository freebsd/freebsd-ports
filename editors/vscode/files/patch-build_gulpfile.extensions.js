--- build/gulpfile.extensions.js.orig	2022-05-16 17:42:35 UTC
+++ build/gulpfile.extensions.js
@@ -222,7 +222,7 @@ const cleanExtensionsBuildTask = task.define('clean-ex
 const compileExtensionsBuildTask = task.define('compile-extensions-build', task.series(
 	cleanExtensionsBuildTask,
 	task.define('bundle-extensions-build', () => ext.packageLocalExtensionsStream(false).pipe(gulp.dest('.build'))),
-	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false, product.extensionsGallery?.serviceUrl).pipe(gulp.dest('.build'))),
+//	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false, product.extensionsGallery?.serviceUrl).pipe(gulp.dest('.build'))),
 ));
 
 gulp.task(compileExtensionsBuildTask);
