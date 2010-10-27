--- src/utils/fs.py.orig	2010-05-23 14:46:21.000000000 +0400
+++ src/utils/fs.py	2010-10-27 03:55:25.000000000 +0400
@@ -203,9 +203,11 @@
 	The function detects system font directories according to detected 
 	system type.
 	"""
+	if system.get_os_family()==system.FREEBSD:
+		return ['/usr/local/lib/X11/fonts', os.path.join(gethome(),'.fonts')]
 	if system.get_os_family()==system.LINUX:
 		return ['/usr/share/fonts', os.path.join(gethome(),'.fonts')]
-	if  system.get_os_family()==system.WINDOWS:
+	if system.get_os_family()==system.WINDOWS:
 		try:
 			import _winreg
 		except ImportError:
@@ -311,4 +313,4 @@
 if __name__ == '__main__':
     _test()
 	
-	
\ No newline at end of file
+	
