--- build/gulpfile.extensions.js.orig	2024-02-27 22:50:23 UTC
+++ build/gulpfile.extensions.js
@@ -239,7 +239,7 @@ const compileExtensionsBuildTask = task.define('compil
 const cleanExtensionsBuildTask = task.define('clean-extensions-build', util.rimraf('.build/extensions'));
 const compileExtensionsBuildTask = task.define('compile-extensions-build', task.series(
 	cleanExtensionsBuildTask,
-	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false).pipe(gulp.dest('.build'))),
+	// task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false).pipe(gulp.dest('.build'))),
 	task.define('bundle-extensions-build', () => ext.packageLocalExtensionsStream(false, false).pipe(gulp.dest('.build'))),
 ));
 
