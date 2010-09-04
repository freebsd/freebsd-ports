--- unix/ibus/gen_mozc_xml.py.org	2010-09-03 21:07:35.757153220 +0900
+++ unix/ibus/gen_mozc_xml.py	2010-09-03 21:11:23.381492067 +0900
@@ -47,7 +47,7 @@
     'description': '%s Component',
     # TODO(yusukes): Support Linux distributions other than Gentoo/ChromeOS.
     # For example, Ubuntu uses /usr/lib/ibus-mozc/.
-    'exec': '/usr/libexec/ibus-engine-mozc --ibus',
+    'exec': '@@LOCALBASE@@/libexec/ibus-engine-mozc --ibus',
     # TODO(mazda): Generate the version number.
     'version': '0.0.0.0',
     'author': 'Google Inc.',
@@ -60,7 +60,7 @@
 IBUS_ENGINE_COMMON_PROPS = {
     'description': '%s (Japanese Input Method)',
     'language': 'ja',
-    'icon': '/usr/share/ibus-mozc/product_icon.png',
+    'icon': '@@LOCALBASE@@/share/ibus-mozc/icons/product_logo.png',
     'rank': '0',
 }
 
