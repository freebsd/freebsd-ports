--- src/build_mozc.py.orig	2016-03-13 11:22:55.000000000 +0900
+++ src/build_mozc.py	2016-05-11 00:18:16.131052000 +0900
@@ -354,6 +354,11 @@
   parser.add_option('--version_file', dest='version_file',
                     help='use the specified version template file',
                     default='mozc_version_template.txt')
+  parser.add_option('--localbase', dest='localbase')
+  parser.add_option('--ldflags', dest='ldflags')
+  parser.add_option('--cflags', dest='cflags')
+  parser.add_option('--cflags_cc', dest='cflags_cc')
+  parser.add_option('--include_dirs', dest='include_dirs')
   AddTargetPlatformOption(parser)
 
   # Mac and Linux
@@ -368,6 +373,14 @@
                     default='',
                     help='A path to the directory where the server executable'
                     'is installed. This option is used only on Linux.')
+  parser.add_option('--renderer_dir', dest='renderer_dir',
+                    default='',
+                    help='A path to the directory where the renderer executable'
+                    'is installed. This option is used only on Linux.')
+  parser.add_option('--tool_dir', dest='tool_dir',
+                    default='',
+                    help='A path to the directory where the tool executable'
+                    'is installed. This option is used only on Linux.')
 
   # Android
   parser.add_option('--android_arch', dest='android_arch',
@@ -522,6 +535,11 @@
   """Parses command line options for the build command."""
   parser = optparse.OptionParser(usage='Usage: %prog build [options]')
   AddCommonOptions(parser)
+  if IsLinux():
+    default_build_concurrency = 1;
+    parser.add_option('--jobs', '-j', dest='jobs',
+                      default=('%d' % default_build_concurrency),
+                      metavar='N', help='run build jobs in parallel')
   parser.add_option('--configuration', '-c', dest='configuration',
                     default='Debug', help='specify the build configuration.')
 
@@ -672,6 +690,17 @@
   logging.info('Building GYP command line...')
   gyp_options = ['--depth=.', '--include=%s/gyp/common.gypi' % SRC_DIR]
 
+  localbase = options.localbase or '/usr'
+  gyp_options.extend(['-D', 'localbase=%s' % localbase])
+
+  ldflags = options.ldflags or ''
+  gyp_options.extend(['-D', 'ldflags=%s' % ldflags])
+  cflags = options.cflags or ''
+  gyp_options.extend(['-D', 'cflags=%s' % cflags])
+  cflags_cc = options.cflags_cc or ''
+  gyp_options.extend(['-D', 'cflags_cc=%s' % cflags_cc])
+  include_dirs = options.include_dirs or ''
+  gyp_options.extend(['-D', 'include_dirs=%s' % include_dirs])
 
   mozc_root = os.path.abspath(GetTopLevelSourceDirectoryName())
   gyp_options.extend(['-D', 'abs_depth=%s' % mozc_root])
@@ -876,6 +905,14 @@
   if options.server_dir:
     gyp_options.extend([
         '-D', 'server_dir=%s' % os.path.abspath(options.server_dir)])
+  if options.tool_dir:
+    gyp_options.extend([
+        '-D', 'tool_dir=%s' % os.path.abspath(options.tool_dir)])
+  if options.renderer_dir:
+    gyp_options.extend([
+        '-D', 'renderer_dir=%s' % os.path.abspath(options.renderer_dir)])
+
+
 
   if generator == 'ninja':
     gyp_options.extend(['--generator-output=.'])
