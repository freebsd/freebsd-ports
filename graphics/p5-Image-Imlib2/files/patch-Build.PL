--- Build.PL.orig	Thu Sep 11 15:09:42 2003
+++ Build.PL	Thu Sep 11 15:09:48 2003
@@ -30,7 +30,7 @@
     'Test::More' => '0.01',
   },
   extra_linker_flags => $libs,
-  cc_flags => $cflags,
+  extra_compiler_flags => $cflags,
   c_source     => './lib/Image',                                               
 );
 $build->create_build_script;
