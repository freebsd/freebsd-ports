--- quisk.py.orig	2018-06-11 21:58:22 UTC
+++ quisk.py
@@ -21,6 +21,11 @@ os.chdir(os.path.normpath(os.path.dirnam
 if sys.path[0] != "'.'":		# Make sure the current working directory is on path
   sys.path.insert(0, '.')
 
+# Hack to ensure unicode is available.
+import locale
+if locale.nl_langinfo(locale.CODESET) == 'US-ASCII':
+        locale.setlocale(locale.LC_ALL, 'en_US.UTF-8')
+
 import wxversion				# Thanks to Mario, DH5YM
 wxversion.ensureMinimal('2.8')
 
