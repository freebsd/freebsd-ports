--- build/detectsys.py.orig	2009-12-05 18:55:51.000000000 +0000
+++ build/detectsys.py
@@ -57,7 +57,7 @@ def detectOS():
 	Raises ValueError if no known OS is detected.
 	'''
 	os = system().lower()
-	if os in ('linux', 'darwin', 'freebsd', 'netbsd', 'openbsd', 'gnu'):
+	if os in ('linux', 'darwin', 'dragonfly', 'freebsd', 'netbsd', 'openbsd', 'gnu'):
 		return os
 	elif os.startswith('gnu/'):
 		# GNU userland on non-Hurd kernel, for example Debian GNU/kFreeBSD.
