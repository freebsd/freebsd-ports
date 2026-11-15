--- build/modules/unified/modulemap_config.py.orig	2026-10-19 21:50:55 UTC
+++ build/modules/unified/modulemap_config.py
@@ -62,7 +62,7 @@ def headers(os):
 
 
 def headers(os):
-    is_linux = os == 'linux'
+    is_linux = os == 'linux' or os == 'openbsd' or os == 'freebsd'
     is_android = os == 'android'
     is_ios = os == 'ios'
     is_mac = os == 'mac'
