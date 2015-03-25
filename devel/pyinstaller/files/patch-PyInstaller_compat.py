--- PyInstaller/compat.py.orig	2013-09-15 20:27:11 UTC
+++ PyInstaller/compat.py
@@ -31,6 +31,7 @@ is_darwin = sys.platform == 'darwin'  # 
 
 # Unix platforms
 is_linux = sys.platform.startswith('linux')
+is_freebsd = sys.platform.startswith('freebsd')
 is_solar = sys.platform.startswith('sun')  # Solaris
 is_aix = sys.platform.startswith('aix')
 
@@ -38,7 +39,7 @@ is_aix = sys.platform.startswith('aix')
 # (e.g. Linux, Solaris, AIX)
 # Mac OS X is not considered as unix since there are many
 # platform specific details for Mac in PyInstaller.
-is_unix = is_linux or is_solar or is_aix
+is_unix = is_linux or is_freebsd or is_solar or is_aix
 
 
 # Correct extension ending: 'c' or 'o'
