--- Build.PL.orig	Sun Aug 31 17:15:33 2003
+++ Build.PL	Thu Oct 23 09:31:34 2003
@@ -21,6 +21,7 @@
 
 my $libs = `$CONFIG --libs`;
 my $cflags = `$CONFIG --cflags`;
+$cflags .= ' -fPIC';
 
 my $build = Module::Build->new(
   module_name => 'Image::Imlib2',
@@ -30,7 +31,7 @@
     'Test::More' => '0.01',
   },
   extra_linker_flags => $libs,
-  cc_flags => $cflags,
+  extra_compiler_flags => $cflags,
   c_source     => './lib/Image',                                               
 );
 $build->create_build_script;
