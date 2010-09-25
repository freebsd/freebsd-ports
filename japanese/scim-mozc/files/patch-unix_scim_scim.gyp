--- unix/scim/scim.gyp.org	2010-09-25 11:26:23.393336519 +0900
+++ unix/scim/scim.gyp	2010-09-25 11:26:45.064334370 +0900
@@ -44,7 +44,7 @@
       '../../session/session.gyp:session',
     ],
     'scim_defines': [
-      'SCIM_ICONDIR="<!@(pkg-config --variable=icondir scim)"',
+      'SCIM_ICONDIR="@@LOCALBASE@@/share/scim-mozc/icons/"',
     ]
   },
   'targets': [
