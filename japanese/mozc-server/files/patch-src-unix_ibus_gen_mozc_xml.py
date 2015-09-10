--- src/unix/ibus/gen_mozc_xml.py.orig	2015-02-15 04:18:31.000000000 +0900
+++ src/unix/ibus/gen_mozc_xml.py	2015-02-22 02:00:23.000000000 +0900
@@ -67,7 +67,7 @@
 # Information to generate <engines> part of mozc.xml for IBus 1.5 or later.
 IBUS_1_5_ENGINE_COMMON_PROPS = {
     'description': '%(product_name)s (Japanese Input Method)',
-    'language': 'ja',
+    'language': 'jpn',
     'icon': '%(ibus_mozc_icon_path)s',
     'rank': '80',
     'symbol': '&#x3042;',
@@ -91,7 +91,7 @@
         # unix/ibus/mozc_engine.cc.
         'name': ['mozc-jp'],
         'longname': ['%(product_name)s'],
-        'layout': ['default'],
+        'layout': ['jp'],
     },
 }
 
@@ -129,6 +129,7 @@
     engines: A dictionary from a property name to a list of property values of
         engines. For example, {'name': ['mozc-jp', 'mozc', 'mozc-dv']}.
   """
+  print '<?xml version="1.0" encoding="utf-8"?>'
   print '<component>'
   for key in component:
     OutputXmlElement(param_dict, key, component[key])
@@ -203,13 +204,19 @@
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
