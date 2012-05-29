--- unix/scim/scim.gyp.orig	2012-05-29 15:36:59.667960727 +0900
+++ unix/scim/scim.gyp	2012-05-01 12:45:44.903691176 +0900
@@ -39,7 +39,7 @@
       'gtk+-2.0',
     ],
     'scim_defines': [
-      'SCIM_ICONDIR="<!@(<(pkg_config_command) --variable=icondir scim)"',
+      'SCIM_ICONDIR="@@LOCALBASE@@/share/scim-mozc/icons/"',
     ]
   },
   'targets': [
