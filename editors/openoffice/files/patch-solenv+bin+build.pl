--- ../solenv/bin/build.pl.orig	Sun Jan 19 00:08:38 2003
+++ ../solenv/bin/build.pl	Sun Jan 19 00:07:25 2003
@@ -292,7 +292,6 @@
 		cwd();
 		$! = 0;
 		system ("$dmake");
-		&print_error("dmake - " . lc($!)) if ($!);
 		if ($? && ($? != -1) && (!$child)) {
 			&print_error("Error $? occurred while making $BuildDir");
 		};
