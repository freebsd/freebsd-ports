--- Build.PL.orig	2010-02-06 19:56:18.143663089 +0900
+++ Build.PL	2010-02-06 19:56:30.643953463 +0900
@@ -337,7 +337,6 @@
 	script_files => ['bin/zim'],
 	data_files => { share => 'share' },
 	requires => {
-		'perl'           => '5.8.0',
 		'Gtk2'           => '1.040',
 		# Older doesn't support Gtk2::UIManager I think
 		'POSIX'          => 0,
