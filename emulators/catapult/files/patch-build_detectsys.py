--- build/detectsys.py.orig	2021-08-16 20:45:31 UTC
+++ build/detectsys.py
@@ -10,7 +10,7 @@ def detectOS():
 	Raises ValueError if no known OS is detected.
 	'''
 	os = system().lower()
-	if os in ('linux', 'darwin', 'freebsd', 'netbsd', 'openbsd', 'gnu'):
+	if os in ('linux', 'darwin', 'dragonfly', 'freebsd', 'netbsd', 'openbsd', 'gnu'):
 		return os
 	elif os.startswith('gnu/'):
 		# GNU userland on non-Hurd kernel, for example Debian GNU/kFreeBSD.
