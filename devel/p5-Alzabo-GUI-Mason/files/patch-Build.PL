--- Build.PL~	Wed Feb 18 19:54:38 2004
+++ Build.PL	Wed Oct 13 15:37:16 2004
@@ -45,8 +45,6 @@
     my $default = $config->{mason_web_dir};
     $default =~ s,/alzabo\Z,, if $default;
 
-    do
-    {
 	print "\n *** The directory you selected does not exist ***\n"
             if defined $config->{mason_web_dir} && ! -d $config->{mason_web_dir};
 
@@ -61,11 +59,7 @@
 server's document root will work.
 EOF
 
-	$config->{mason_web_dir} =
-	    Module::Build->prompt( '  Mason directory?', $default || '' );
-    } while ( ! -d $config->{mason_web_dir} );
-
-    $config->{mason_web_dir} = File::Spec->catdir( $config->{mason_web_dir}, 'alzabo' );
+	$config->{mason_web_dir} = $ENV{DATADIR};
 
     print <<'EOF';
 
@@ -76,9 +70,7 @@
 EOF
 
 
-    $config->{mason_extension} =
-	Module::Build->prompt( '  Mason component file extension?',
-			       $config->{mason_extension} || '.mhtml' );
+    $config->{mason_extension} = '.mhtml';
 
     write_config_module($config);
 }
