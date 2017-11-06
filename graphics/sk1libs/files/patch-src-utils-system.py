--- src/utils/system.py.orig	2010-03-08 00:15:33 UTC
+++ src/utils/system.py
@@ -22,6 +22,7 @@ import platform, os, string, re, stat
 
 WINDOWS = 'Windows'
 LINUX = 'Linux'
+FREEBSD = 'FreeBSD'
 MACOSX = 'Darwin'
 GENERIC = 'generic'
 
@@ -33,6 +34,8 @@ def get_os_family():
 	name = platform.system()
 	if name == LINUX:
 		return LINUX
+	elif name == FREEBSD:
+		return FREEBSD
 	elif name == WINDOWS:
 		return WINDOWS
 	elif name == MACOSX:
