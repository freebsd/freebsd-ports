--- src/utils/fs.py.orig	2010-05-23 10:46:21 UTC
+++ src/utils/fs.py
@@ -203,9 +203,11 @@ def get_system_fontdirs():
 	The function detects system font directories according to detected 
 	system type.
 	"""
+	if system.get_os_family()==system.FREEBSD:
+		return ['/usr/local/lib/X11/fonts', '/usr/local/share/fonts', os.path.join(gethome(),'.fonts')]
 	if system.get_os_family()==system.LINUX:
 		return ['/usr/share/fonts', os.path.join(gethome(),'.fonts')]
-	if  system.get_os_family()==system.WINDOWS:
+	if system.get_os_family()==system.WINDOWS:
 		try:
 			import _winreg
 		except ImportError:
@@ -311,4 +313,4 @@ def _test():
 if __name__ == '__main__':
     _test()
 	
-	
\ No newline at end of file
+	
