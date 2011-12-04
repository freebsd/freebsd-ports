--- unix/scim/scim.gyp.orig	2011-12-04 16:22:26.127609806 +0900
+++ unix/scim/scim.gyp	2011-12-04 16:39:02.023609368 +0900
@@ -39,7 +39,7 @@
       'gtk+-2.0',
     ],
     'scim_defines': [
-      'SCIM_ICONDIR="<!@(<(pkg_config_command) --variable=icondir scim)"',
+      'SCIM_ICONDIR="@@LOCALBASE@@/share/scim-mozc/icons/"',
     ]
   },
   'targets': [
