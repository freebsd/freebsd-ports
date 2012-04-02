--- unix/scim/scim.gyp.orig	2012-04-02 08:17:52.708727144 +0900
+++ unix/scim/scim.gyp	2012-04-02 08:24:24.095725631 +0900
@@ -39,7 +39,7 @@
       'gtk+-2.0',
     ],
     'scim_defines': [
-      'SCIM_ICONDIR="<!@(<(pkg_config_command) --variable=icondir scim)"',
+      'SCIM_ICONDIR="@@LOCALBASE@@/share/scim-mozc/icons/"',
     ]
   },
   'targets': [
