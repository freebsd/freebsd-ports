--- src/unix/fcitx/fcitx.gyp.orig	2017-01-01 15:13:15.000000000 +0900
+++ src/unix/fcitx/fcitx.gyp	2017-01-02 01:52:57.325440000 +0900
@@ -47,8 +47,14 @@
         '../../protocol/protocol.gyp:commands_proto',
     ],
     'fcitx_defines': [
-      'LOCALEDIR="<!@(fcitx4-config --prefix)/share/locale/"',
-    ]
+    ],
+    'conditions': [
+      ['use_fcitx==1', {
+        'fcitx_defines': [
+          'LOCALEDIR="<!@(fcitx4-config --prefix)/share/locale/"',
+        ]
+      }]
+    ],
   },
   'targets': [
     {
@@ -90,8 +96,12 @@
         '<@(fcitx_dependencies)',
         'gen_fcitx_mozc_i18n',
       ],
-      'cflags': [
-        '<!@(pkg-config --cflags <@(pkg_config_libs))',
+      'conditions': [
+        ['use_fcitx==1', {
+          'cflags': [
+            '<!@(pkg-config --cflags <@(pkg_config_libs))',
+          ],
+        }],
       ],
       'include_dirs': [
         '<@(fcitx_dep_include_dirs)',
