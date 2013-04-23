--- unix/ibus/gen_mozc_xml.py.orig	2013-04-21 03:48:44.433270458 +0900
+++ unix/ibus/gen_mozc_xml.py	2013-04-21 04:12:50.384269164 +0900
@@ -41,6 +41,7 @@
 import os
 import subprocess
 import sys
+import os
 
 # Information to generate <component> part of mozc.xml. %s will be replaced with
 # a product name, 'Mozc' or 'Google Japanese Input'.
@@ -75,6 +76,32 @@
     'symbol': '&#x3042;',
 }
 
+# Override for FreeBSD
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
+  IBUS_1_5_ENGINE_COMMON_PROPS = {
+    'description': '%s (Japanese Input Method)',
+    'language': 'ja',
+    'icon': '@@LOCALBASE@@/share/ibus-mozc/icons/product_logo.png',
+    'rank': '80',
+    'symbol': '&#x3042;',
+  }
+
 # A dictionary from --platform to engines that are used in the platform. The
 # information is used to generate <engines> part of mozc.xml.
 IBUS_ENGINES_PROPS = {
