--- Build.PL~	Thu Jun 10 01:00:41 2004
+++ Build.PL	Sun Aug  8 10:55:14 2004
@@ -90,7 +90,7 @@
 EOF
 
     my $root_dir = Alzabo::Config::root_dir() if %Alzabo::Config::CONFIG;
-    return Module::Build->prompt( '  Alzabo root?', $root_dir || find_possible_root() );
+    return undef;
 }
 
 sub find_possible_root
@@ -182,8 +182,7 @@
 
 	print "\u$feature->{phrase} $mods.\n";
 
-	my $wanted =
-            Module::Build->y_n( "  Do you want $feature->{phrase}?", $has ? 'yes' : 'no' );
+	my $wanted;
 
 	if ($wanted)
 	{
