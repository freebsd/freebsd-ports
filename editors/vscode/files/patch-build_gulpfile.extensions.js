--- build/gulpfile.extensions.js.orig	2020-08-25 09:40:01 UTC
+++ build/gulpfile.extensions.js
@@ -166,7 +166,7 @@ const cleanExtensionsBuildTask = task.define('clean-ex
 const compileExtensionsBuildTask = task.define('compile-extensions-build', task.series(
 	cleanExtensionsBuildTask,
 	task.define('bundle-extensions-build', () => ext.packageLocalExtensionsStream(false).pipe(gulp.dest('.build'))),
-	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false).pipe(gulp.dest('.build'))),
+//	task.define('bundle-marketplace-extensions-build', () => ext.packageMarketplaceExtensionsStream(false).pipe(gulp.dest('.build'))),
 ));
 
 gulp.task(compileExtensionsBuildTask);
@@ -244,5 +244,3 @@ async function buildWebExtensions(isWatch) {
 		}
 	});
 }
-
-
