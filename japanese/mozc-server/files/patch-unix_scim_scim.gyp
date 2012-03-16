--- unix/scim/scim.gyp.orig	2012-03-16 10:48:02.019712085 +0900
+++ unix/scim/scim.gyp	2012-03-16 10:59:20.258715241 +0900
@@ -39,7 +39,7 @@
       'gtk+-2.0',
     ],
     'scim_defines': [
-      'SCIM_ICONDIR="<!@(<(pkg_config_command) --variable=icondir scim)"',
+      'SCIM_ICONDIR="@@LOCALBASE@@/share/scim-mozc/icons/"',
     ]
   },
   'targets': [
