--- unix/ibus/gen_mozc_xml.py.orig	2015-02-17 18:05:39.000000000 +0900
+++ unix/ibus/gen_mozc_xml.py	2015-02-17 18:06:30.000000000 +0900
@@ -203,13 +203,19 @@
   parser.add_option('--server_dir', dest='server_dir', default='',
                     help='The absolute directory path to be installed the '
                     'server executable.')
+  parser.add_option('--renderer_dir', dest='renderer_dir', default='',
+                    help='The absolute directory path to be installed the '
+                    'renderer executable.')
+  parser.add_option('--tool_dir', dest='tool_dir', default='',
+                    help='The absolute directory path to be installed the '
+                    'tool executable.')
   parser.add_option('--pkg_config_command', dest='pkg_config_command',
                     default='pkg-config',
                     help='The path to pkg-config command.')
   (options, unused_args) = parser.parse_args()
 
   setup_arg = []
-  setup_arg.append(os.path.join(options.server_dir, 'mozc_tool'))
+  setup_arg.append(os.path.join(options.tool_dir, 'mozc_tool'))
   setup_arg.append('--mode=config_dialog')
   if IsIBus15OrGreater(options):
     # A tentative workaround against IBus 1.5
