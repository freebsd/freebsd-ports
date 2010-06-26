--- unix/scim/scim.gyp.org	2010-06-17 15:59:08.047320852 +0900
+++ unix/scim/scim.gyp	2010-06-26 18:03:23.532337010 +0900
@@ -43,17 +43,15 @@
     # on Ubuntu Hardy. Until it becomes necessary, we will not invoke
     # pkg-config here.
     'scim_include_dirs': [
-      '/usr/include/atk-1.0',
-      '/usr/include/cairo',
-      '/usr/include/freetype2',
-      '/usr/include/glib-2.0',
-      '/usr/include/gtk-2.0',
-      '/usr/include/libpng12',
-      '/usr/include/pango-1.0',
-      '/usr/include/pixman-1',
-      '/usr/include/scim-1.0',
-      '/usr/lib/glib-2.0/include',
-      '/usr/lib/gtk-2.0/include',
+      '@@LOCALBASE@@/include/atk-1.0',
+      '@@LOCALBASE@@/include/cairo',
+      '@@LOCALBASE@@/include/freetype2',
+      '@@LOCALBASE@@/include/glib-2.0',
+      '@@LOCALBASE@@/include/gtk-2.0',
+      '@@LOCALBASE@@/include/libpng',
+      '@@LOCALBASE@@/include/pango-1.0',
+      '@@LOCALBASE@@/include/pixman-1',
+      '@@LOCALBASE@@/include/scim-1.0',
     ],
     # The libraries come from "pkg-config --libs-only-l scim gtk+-2.0".
     'scim_libraries': [
@@ -74,7 +72,7 @@
       '-fPIC',
     ],
     'scim_defines': [
-      'SCIM_ICONDIR="/usr/share/scim/icons"',
+      'SCIM_ICONDIR="@@LOCALBASE@@/share/mozc-additions/icons/"',
     ]
   },
   'targets': [
