--- build_mozc.py.orig	2013-03-29 13:33:25.000000000 +0900
+++ build_mozc.py	2013-05-02 00:54:37.000000000 +0900
@@ -332,6 +332,14 @@
                     help='use rsync to copy files instead of builtin function')
   AddTargetPlatformOption(parser)
 
+  parser.add_option('--localbase', dest='localbase')
+  parser.add_option('--ldflags', dest='ldflags')
+  parser.add_option('--include_dirs', dest='include_dirs')
+  parser.add_option('--openssl_cflags', dest='openssl_cflags')
+  parser.add_option('--openssl_ldflags', dest='openssl_ldflags')
+  parser.add_option('--openssl_lib', dest='openssl_lib')
+  parser.add_option('--openssl_inc', dest='openssl_inc')
+
   parser.add_option('--mac_dir', dest='mac_dir',
                     help='A path to the root directory of third party '
                     'libraries for Mac build which will be passed to gyp '
@@ -506,7 +514,7 @@
   parser = optparse.OptionParser(usage='Usage: %prog build [options]')
   AddCommonOptions(parser)
   if IsLinux():
-    default_build_concurrency = GetNumberOfProcessors() * 2
+    default_build_concurrency = 1;
     parser.add_option('--jobs', '-j', dest='jobs',
                       default=('%d' % default_build_concurrency),
                       metavar='N', help='run build jobs in parallel')
@@ -709,7 +717,22 @@
         command_line.extend(['-D', 'enable_unittest=0'])
         break
 
+  localbase = options.localbase or '/usr'
+  command_line.extend(['-D', 'localbase=%s' % localbase])
 
+  ldflags = options.ldflags or ''
+  command_line.extend(['-D', 'ldflags=%s' % ldflags])
+  include_dirs = options.include_dirs or ''
+  command_line.extend(['-D', 'include_dirs=%s' % include_dirs])
+
+  openssl_cflags = options.openssl_cflags or ''
+  command_line.extend(['-D', 'openssl_cflags=%s' % openssl_cflags])
+  openssl_ldflags = options.openssl_cflags or ''
+  command_line.extend(['-D', 'openssl_ldflags=%s' % openssl_ldflags])
+  openssl_inc = options.openssl_inc or ''
+  command_line.extend(['-D', 'openssl_inc=%s' % openssl_inc])
+  openssl_lib = options.openssl_lib or ''
+  command_line.extend(['-D', 'openssl_lib=%s' % openssl_lib])
 
   mac_dir = options.mac_dir or '../mac'
   if not os.path.isabs(mac_dir):
