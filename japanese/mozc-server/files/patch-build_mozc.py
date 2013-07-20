--- build_mozc.py.orig	2013-07-17 11:37:50.000000000 +0900
+++ build_mozc.py	2013-07-19 22:27:55.000000000 +0900
@@ -332,6 +332,13 @@
                     help='use rsync to copy files instead of builtin function')
   AddTargetPlatformOption(parser)
 
+  parser.add_option('--localbase', dest='localbase')
+  parser.add_option('--ldflags', dest='ldflags')
+  parser.add_option('--include_dirs', dest='include_dirs')
+  parser.add_option('--openssl_cflags', dest='openssl_cflags')
+  parser.add_option('--openssl_ldflags', dest='openssl_ldflags')
+  parser.add_option('--openssl_lib', dest='openssl_lib')
+  parser.add_option('--openssl_inc', dest='openssl_inc')
 
   # Mac and Linux
   warn_as_error_default = False
@@ -518,7 +525,7 @@
   parser = optparse.OptionParser(usage='Usage: %prog build [options]')
   AddCommonOptions(parser)
   if IsLinux():
-    default_build_concurrency = GetNumberOfProcessors() * 2
+    default_build_concurrency = 1;
     parser.add_option('--jobs', '-j', dest='jobs',
                       default=('%d' % default_build_concurrency),
                       metavar='N', help='run build jobs in parallel')
@@ -566,9 +573,6 @@
 
   return parser.parse_args(args, values)
 
-
-
-
 def AddPythonPathToEnvironmentFilesForWindows(out_dir):
   """Add PYTHONPATH to environment files for Ninja."""
   mozc_root = os.path.abspath(GetTopLevelSourceDirectoryName())
@@ -746,6 +750,22 @@
   else:
     command_line.extend(['-D', 'warn_as_error=0'])
 
+  localbase = options.localbase or '/usr'
+  command_line.extend(['-D', 'localbase=%s' % localbase])
+
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
 
   # mac_dir should be started with '<(DEPTH)', otherwise some
   # operations in XCode fails.  So if the mac_dir option is an
