--- ./lib/sapi.py.orig	2010-03-29 17:32:43.000000000 +0200
+++ ./lib/sapi.py	2010-05-07 18:36:29.000000000 +0200
@@ -33,6 +33,7 @@
 # that character as-is, and sometimes needs to embed escaped values
 # into HTML attributes.
 def escape(s):
+  s = str(s)
   s = string.replace(s, '&', '&amp;')
   s = string.replace(s, '>', '&gt;')
   s = string.replace(s, '<', '&lt;')
