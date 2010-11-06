--- unix/scim/scim.gyp.org	2010-11-06 10:58:16.438187044 +0900
+++ unix/scim/scim.gyp	2010-11-06 10:58:34.829186459 +0900
@@ -44,7 +44,7 @@
       '../../session/session.gyp:session',
     ],
     'scim_defines': [
-      'SCIM_ICONDIR="<!@(pkg-config --variable=icondir scim)"',
+      'SCIM_ICONDIR="@@LOCALBASE@@/share/scim-mozc/icons/"',
     ]
   },
   'targets': [
