--- unix/scim/scim.gyp.orig	2012-01-29 13:42:31.153806065 +0900
+++ unix/scim/scim.gyp	2012-01-29 13:49:16.076805497 +0900
@@ -39,7 +39,7 @@
       'gtk+-2.0',
     ],
     'scim_defines': [
-      'SCIM_ICONDIR="<!@(<(pkg_config_command) --variable=icondir scim)"',
+      'SCIM_ICONDIR="@@LOCALBASE@@/share/scim-mozc/icons/"',
     ]
   },
   'targets': [
