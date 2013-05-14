--- unix/ibus/gen_mozc_xml.py.orig	2013-03-29 13:33:43.000000000 +0900
+++ unix/ibus/gen_mozc_xml.py	2013-04-28 20:40:28.000000000 +0900
@@ -46,10 +46,10 @@
 # a product name, 'Mozc' or 'Google Japanese Input'.
 IBUS_COMPONENT_PROPS = {
     'name': 'com.google.IBus.Mozc',
-    'description': '%s Component',
+    'description': '%(product_name)s Component',
     # TODO(yusukes): Support Linux distributions other than Gentoo/ChromeOS.
     # For example, Ubuntu uses /usr/lib/ibus-mozc/.
-    'exec': '/usr/libexec/ibus-engine-mozc --ibus',
+    'exec': '%(localbase)s/libexec/ibus-engine-mozc --ibus',
     # TODO(mazda): Generate the version number.
     'version': '0.0.0.0',
     'author': 'Google Inc.',
@@ -60,17 +60,17 @@
 
 # Information to generate <engines> part of mozc.xml.
 IBUS_ENGINE_COMMON_PROPS = {
-    'description': '%s (Japanese Input Method)',
+    'description': '%(product_name)s (Japanese Input Method)',
     'language': 'ja',
-    'icon': '/usr/share/ibus-mozc/product_icon.png',
+    'icon': '%(localbase)s/share/ibus-mozc/icons/product_icon.png',
     'rank': '80',
 }
 
 # Information to generate <engines> part of mozc.xml for IBus 1.5 or later.
 IBUS_1_5_ENGINE_COMMON_PROPS = {
-    'description': '%s (Japanese Input Method)',
+    'description': '%(product_name)s (Japanese Input Method)',
     'language': 'ja',
-    'icon': '/usr/share/ibus-mozc/product_icon.png',
+    'icon': '%(localbase)s/share/ibus-mozc/icons/product_icon.png',
     'rank': '80',
     'symbol': '&#x3042;',
 }
@@ -83,7 +83,7 @@
         # DO NOT change the engine name 'mozc-jp'. The names is referenced by
         # unix/ibus/mozc_engine.cc.
         'name': ['mozc-jp'],
-        'longname': ['%s'],
+        'longname': ['%(product_name)s'],
         'layout': ['jp'],
     },
     # On Linux (IBus >= 1.5), we use special label 'default' for the keyboard
@@ -92,7 +92,7 @@
         # DO NOT change the engine name 'mozc-jp'. The names is referenced by
         # unix/ibus/mozc_engine.cc.
         'name': ['mozc-jp'],
-        'longname': ['%s'],
+        'longname': ['%(product_name)s'],
         'layout': ['default'],
     },
     # On Chrome/Chromium OS, we provide three engines.
@@ -100,8 +100,8 @@
         # DO NOT change the engine name 'mozc-jp'. The names is referenced by
         # unix/ibus/mozc_engine.cc.
         'name': ['mozc-jp', 'mozc', 'mozc-dv'],
-        'longname': ['%s (Japanese keyboard layout)', '%s (US keyboard layout)',
-                     '%s (US Dvorak keyboard layout)'],
+        'longname': ['%(product_name)s (Japanese keyboard layout)', '%(product_name)s (US keyboard layout)',
+                     '%(product_name)s (US Dvorak keyboard layout)'],
         'layout': ['jp', 'us', 'us(dvorak)'],
     },
 }
@@ -123,18 +123,11 @@
 #endif  // %s"""
 
 
-def EmbedProductName(product_name, format_string):
-  if format_string.find('%s') != -1:
-    return format_string % product_name
-  return format_string
-
-
-def OutputXmlElement(product_name, element_name, value):
-  print '  <%s>%s</%s>' % (element_name, EmbedProductName(product_name, value),
-                           element_name)
+def OutputXmlElement(element_name, value):
+  print '  <%s>%s</%s>' % (element_name, value, element_name)
 
 
-def OutputXml(product_name, component, engine_common, engines, setup_arg):
+def OutputXml(product_name, component, engine_common, engines, setup_arg, localbase):
   """Outputs a XML data for ibus-daemon.
 
   Args:
@@ -148,27 +141,25 @@
   """
   print '<component>'
   for key in component:
-    OutputXmlElement(product_name, key, component[key])
+    OutputXmlElement(key, component[key] % locals())
   print '<engines>'
   for i in range(len(engines['name'])):
     print '<engine>'
     for key in engine_common:
-      OutputXmlElement(product_name, key, engine_common[key])
+      OutputXmlElement(key, engine_common[key] % locals())
     if setup_arg:
-      OutputXmlElement(product_name, 'setup', ' '.join(setup_arg))
+      OutputXmlElement('setup', ' '.join(setup_arg))
     for key in engines:
-      OutputXmlElement(product_name, key, engines[key][i])
+      OutputXmlElement(key, engines[key][i] % locals())
     print '</engine>'
   print '</engines>'
   print '</component>'
 
 
-def OutputCppVariable(product_name, prefix, variable_name, value):
-  print 'const char k%s%s[] = "%s";' % (prefix, variable_name.capitalize(),
-                                        EmbedProductName(product_name, value))
-
+def OutputCppVariable(prefix, variable_name, value):
+  print 'const char k%s%s[] = "%s";' % (prefix, variable_name.capitalize(), value)
 
-def OutputCpp(product_name, component, engine_common, engines):
+def OutputCpp(product_name, component, engine_common, engines, localbase):
   """Outputs a C++ header file for mozc/unix/ibus/main.cc.
 
   Args:
@@ -180,13 +171,13 @@
   guard_name = 'MOZC_UNIX_IBUS_MAIN_H_'
   print CPP_HEADER % (guard_name, guard_name)
   for key in component:
-    OutputCppVariable(product_name, 'Component', key, component[key])
+    OutputCppVariable('Component', key, component[key] % locals())
   for key in engine_common:
-    OutputCppVariable(product_name, 'Engine', key, engine_common[key])
+    OutputCppVariable('Engine', key, engine_common[key] % locals())
   for key in engines:
     print 'const char* kEngine%sArray[] = {' % key.capitalize()
     for i in range(len(engines[key])):
-      print '"%s",' % EmbedProductName(product_name, engines[key][i])
+      print '"%s",' % engines[key][i] % locals()
     print '};'
   print 'const size_t kEngineArrayLen = %s;' % len(engines['name'])
   print CPP_FOOTER % guard_name
@@ -222,6 +213,7 @@
   parser.add_option('--pkg_config_command', dest='pkg_config_command',
                     default='pkg-config',
                     help='The path to pkg-config command.')
+  parser.add_option('--localbase', dest='localbase')
   (options, unused_args) = parser.parse_args()
 
   setup_arg = []
@@ -238,12 +230,12 @@
   if options.output_cpp:
     OutputCpp(PRODUCT_NAMES[options.branding], IBUS_COMPONENT_PROPS,
               common_props,
-              IBUS_ENGINES_PROPS[platform])
+              IBUS_ENGINES_PROPS[platform], options.localbase)
   else:
     OutputXml(PRODUCT_NAMES[options.branding], IBUS_COMPONENT_PROPS,
               common_props,
               IBUS_ENGINES_PROPS[platform],
-              setup_arg)
+              setup_arg, options.localbase)
   return 0
 
 if __name__ == '__main__':
