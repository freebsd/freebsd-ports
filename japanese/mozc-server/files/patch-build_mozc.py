--- build_mozc.py.orig	2014-08-31 03:36:22.000000000 +0900
+++ build_mozc.py	2014-08-31 06:04:34.000000000 +0900
@@ -351,6 +351,9 @@
   parser.add_option('--version_file', dest='version_file',
                     help='use the specified version template file',
                     default='mozc_version_template.txt')
+  parser.add_option('--localbase', dest='localbase')
+  parser.add_option('--ldflags', dest='ldflags')
+  parser.add_option('--include_dirs', dest='include_dirs')
   AddTargetPlatformOption(parser)
 
   # Mac and Linux
@@ -538,7 +541,7 @@
   parser = optparse.OptionParser(usage='Usage: %prog build [options]')
   AddCommonOptions(parser)
   if IsLinux():
-    default_build_concurrency = GetNumberOfProcessors() * 2
+    default_build_concurrency = 1;
     parser.add_option('--jobs', '-j', dest='jobs',
                       default=('%d' % default_build_concurrency),
                       metavar='N', help='run build jobs in parallel')
@@ -701,6 +704,13 @@
   logging.info('Building GYP command line...')
   gyp_options = ['--depth=.', '--include=%s/gyp/common.gypi' % SRC_DIR]
 
+  localbase = options.localbase or '/usr'
+  gyp_options.extend(['-D', 'localbase=%s' % localbase])
+
+  ldflags = options.ldflags or ''
+  gyp_options.extend(['-D', 'ldflags=%s' % ldflags])
+  include_dirs = options.include_dirs or ''
+  gyp_options.extend(['-D', 'include_dirs=%s' % include_dirs])
 
   mozc_root = os.path.abspath(GetTopLevelSourceDirectoryName())
   gyp_options.extend(['-D', 'abs_depth=%s' % mozc_root])
