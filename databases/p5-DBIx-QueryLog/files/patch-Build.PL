--- Build.PL.orig	2013-05-21 08:30:37.755439420 +0900
+++ Build.PL	2013-05-21 08:30:47.893439551 +0900
@@ -27,7 +27,7 @@
     module_name     => 'DBIx::QueryLog',
     allow_pure_perl => 0,
 
-    script_files => [glob('script/*'), glob('bin/*')],
+#    script_files => [glob('script/*'), glob('bin/*')],
 
     test_files           => ((-d '.git' || $ENV{RELEASE_TESTING}) && -d 'xt') ? 't/ xt/' : 't/',
     recursive_test_files => 1,
