--- build/gulpfile.extensions.js.orig	2023-01-09 16:16:14 UTC
+++ build/gulpfile.extensions.js
@@ -236,7 +236,7 @@ exports.compileExtensionMediaBuildTask = compileExtens
 const cleanExtensionsBuildTask = task.define('clean-extensions-build', util.rimraf('.build/extensions'));
 const compileExtensionsBuildTask = task.define('compile-extensions-build', task.series(
 	cleanExtensionsBuildTask,
-	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false).pipe(gulp.dest('.build'))),
+//	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false).pipe(gulp.dest('.build'))),
 	task.define('bundle-extensions-build', () => ext.packageLocalExtensionsStream(false).pipe(gulp.dest('.build'))),
 ));
 
