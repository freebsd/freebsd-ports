--- Build.PL.orig	2014-11-20 15:07:02.244462087 +0900
+++ Build.PL	2014-11-20 15:07:18.822650963 +0900
@@ -25,7 +25,7 @@
     module_name     => 'DBIx::QueryLog',
     allow_pureperl => 0,
 
-    script_files => [glob('script/*'), glob('bin/*')],
+#    script_files => [glob('script/*'), glob('bin/*')],
     c_source     => [qw()],
     PL_files => {},
 
