--- packages/app-desktop/gulpfile.ts.orig	2026-09-07 13:38:53 UTC
+++ packages/app-desktop/gulpfile.ts
@@ -78,7 +78,7 @@ const buildBeforeStartParallel = gulp.parallel(
 utils.registerGulpTasks(gulp, tasks);
 
 const buildBeforeStartParallel = gulp.parallel(
-	'installElectron',
+	// 'installElectron',
 	'compileScripts',
 	'compilePackageInfo',
 	'copyPluginAssets',
