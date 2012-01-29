--- unix/ibus/gen_mozc_xml.py.orig	2012-01-29 13:42:31.153806065 +0900
+++ unix/ibus/gen_mozc_xml.py	2012-01-29 13:49:15.972806246 +0900
@@ -39,6 +39,7 @@
 
 import optparse
 import sys
+import os
 
 # Information to generate <component> part of mozc.xml. %s will be replaced with
 # a product name, 'Mozc' or 'Google Japanese Input'.
@@ -64,6 +65,24 @@
     'rank': '80',
 }
 
+if os.uname()[0] == 'FreeBSD':
+  IBUS_COMPONENT_PROPS = {
+    'name': 'com.google.IBus.Mozc',
+    'description': '%s Component',
+    'exec': '@@LOCALBASE@@/libexec/ibus-engine-mozc --ibus',
+    'version': '0.0.0.0',
+    'author': 'Google Inc.',
+    'license': 'New BSD',
+    'homepage': 'http://code.google.com/p/mozc/',
+    'textdomain': 'ibus-mozc',
+  }
+  IBUS_ENGINE_COMMON_PROPS = {
+    'description': '%s (Japanese Input Method)',
+    'language': 'ja',
+    'icon': '@@LOCALBASE@@/share/ibus-mozc/icons/product_logo.png',
+    'rank': '0',
+  }
+
 # A dictionary from --platform to engines that are used in the platform. The
 # information is used to generate <engines> part of mozc.xml.
 IBUS_ENGINES_PROPS = {
