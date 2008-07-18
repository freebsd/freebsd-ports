--- setup.py.orig	2008-07-10 04:15:26.000000000 +0800
+++ setup.py	2008-07-10 04:15:53.000000000 +0800
@@ -45,8 +45,8 @@
     test_prefix = cclib_prefix + '/test'
     data_prefix = cclib_prefix + '/data'
     cclib_datafiles = [ (cclib_prefix, ['ANNOUNCE', 'CHANGELOG', 'INSTALL', 'LICENSE', 'README', 'THANKS']),
-                        (test_prefix, ['test/testdata']),
-                        (data_prefix, ['data/regressionfiles.txt', 'data/wget.sh'])]
+                        (test_prefix, ['test/testdata'])]
+#                        (data_prefix, ['data/regressionfiles.txt', 'data/wget.sh'])]
     for program in programs:
         data_dirs = os.listdir('data/%s' %program)
         for data_dir in data_dirs:
