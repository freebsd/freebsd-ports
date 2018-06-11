--- quisk.py.orig	2016-11-30 18:26:59 UTC
+++ quisk.py
@@ -21,6 +21,13 @@ os.chdir(os.path.normpath(os.path.dirnam
 if sys.path[0] != "'.'":		# Make sure the current working directory is on path
   sys.path.insert(0, '.')
 
+# Hack to ensure unicode is available.
+import locale
+locale.setlocal(locale.LC_ALL, '')
+cloc = locale.getdefaultlocale()
+if locale.nl_langinfo(locale.CODESET) != 'UTF-8':
+        locale.setlocale(locale.LC_ALL, (cloc[0], 'UTF-8'))
+
 import wxversion				# Thanks to Mario, DH5YM
 wxversion.ensureMinimal('2.8')
 
