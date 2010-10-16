--- unix/scim/scim.gyp.org	2010-10-16 12:08:42.286177748 +0900
+++ unix/scim/scim.gyp	2010-10-16 12:08:59.542185425 +0900
@@ -44,7 +44,7 @@
       '../../session/session.gyp:session',
     ],
     'scim_defines': [
-      'SCIM_ICONDIR="<!@(pkg-config --variable=icondir scim)"',
+      'SCIM_ICONDIR="@@LOCALBASE@@/share/scim-mozc/icons/"',
     ]
   },
   'targets': [
