--- src/unix/ibus/gen_mozc_xml.py.orig	2016-03-13 11:22:55.000000000 +0900
+++ src/unix/ibus/gen_mozc_xml.py	2016-05-10 23:43:06.273350000 +0900
@@ -90,6 +90,7 @@
     engines: A dictionary from a property name to a list of property values of
         engines. For example, {'name': ['mozc-jp', 'mozc', 'mozc-dv']}.
   """
+  print '<?xml version="1.0" encoding="utf-8"?>'
   print '<component>'
   for key in component:
     OutputXmlElement(param_dict, key, component[key])
@@ -164,13 +165,19 @@
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
 
   param_dict = {
@@ -181,7 +188,7 @@
 
   engine_common_props = {
       'description': '%(product_name)s (Japanese Input Method)',
-      'language': 'ja',
+      'language': 'jpn',
       'icon': '%(ibus_mozc_icon_path)s',
       'rank': '80',
   }
