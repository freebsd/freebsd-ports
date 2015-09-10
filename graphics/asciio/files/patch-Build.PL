--- Build.PL.orig	2015-06-30 11:02:36 UTC
+++ Build.PL
@@ -282,7 +282,7 @@ my $build = $class->new
 	pm_files     => \%all_modules,
 	#~ autosplit    => \@split_modules,
 	
-	script_files => ['script/asciio', 'script/asciio_to_text', 'script/A',],
+	script_files => ['script/asciio', 'script/asciio_to_text',],
 	dist_author  => 'Khemir Nadim ibn Hamouda. <nadim@khemir.net>',
 	dist_abstract => 'App::Asciio - ASCII diagramming',
 	);
