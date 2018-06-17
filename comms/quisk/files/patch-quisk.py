--- quisk.py.orig	2016-11-30 13:26:59.000000000 -0500
+++ quisk.py	2018-06-17 10:30:03.031192000 -0400
@@ -21,6 +21,13 @@
 if sys.path[0] != "'.'":		# Make sure the current working directory is on path
   sys.path.insert(0, '.')
 
+# Hack to ensure unicode is available.
+import locale
+locale.setlocale(locale.LC_ALL, '')
+cloc = locale.getdefaultlocale()
+if locale.nl_langinfo(locale.CODESET) != 'UTF-8':
+        locale.setlocale(locale.LC_ALL, (cloc[0], 'UTF-8'))
+
 import wxversion				# Thanks to Mario, DH5YM
 wxversion.ensureMinimal('2.8')
 
