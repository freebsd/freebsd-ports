--- src/utils/system.py.orig	2010-03-08 03:15:33.000000000 +0300
+++ src/utils/system.py	2010-10-27 04:04:27.000000000 +0400
@@ -22,6 +22,7 @@
 
 WINDOWS = 'Windows'
 LINUX = 'Linux'
+FREEBSD = 'FreeBSD'
 MACOSX = 'Darwin'
 GENERIC = 'generic'
 
@@ -33,6 +34,8 @@
 	name = platform.system()
 	if name == LINUX:
 		return LINUX
+	elif name == FREEBSD:
+		return FREEBSD
 	elif name == WINDOWS:
 		return WINDOWS
 	elif name == MACOSX:
