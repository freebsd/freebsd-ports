--- unix/scim/scim.gyp.org	2010-09-18 13:07:44.032136540 +0900
+++ unix/scim/scim.gyp	2010-09-18 13:08:24.780919695 +0900
@@ -44,7 +44,7 @@
       '../../session/session.gyp:session',
     ],
     'scim_defines': [
-      'SCIM_ICONDIR="<!@(pkg-config --variable=icondir scim)"',
+      'SCIM_ICONDIR="@@LOCALBASE@@/share/scim-mozc/icons/"',
     ]
   },
   'targets': [
