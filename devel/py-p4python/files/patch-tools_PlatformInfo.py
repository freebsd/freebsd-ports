--- tools/PlatformInfo.py.orig	2023-04-05 20:18:00 UTC
+++ tools/PlatformInfo.py
@@ -131,9 +131,7 @@ class PlatformInfo:
                 arch = self.architecture(unameOut[4])
             elif unameOut[0] == 'FreeBSD':
                 unix = "FREEBSD"
-                release = unameOut[2][0]
-                if release == '5':
-                    release += unameOut[2][2]
+                release = re.match("(\d+.\d)", unameOut[2]).group(1).replace(".","")
 
                 arch = self.architecture(unameOut[4])
             elif unameOut[0] == 'CYGWIN_NT-5.1':
