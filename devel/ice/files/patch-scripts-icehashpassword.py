--- scripts/icehashpassword.py.orig	2015-06-23 15:30:20.000000000 +0000
+++ scripts/icehashpassword.py	2015-06-27 17:12:00.818709719 +0000
@@ -11,7 +11,7 @@
 import sys, getopt, passlib.hash, getpass
 
 usePBKDF2 = sys.platform == "win32" or sys.platform == "darwin"
-useCryptExt = sys.platform.startswith("linux")
+useCryptExt = sys.platform.startswith("linux") or sys.platform.startswith("freebsd")
 
 if not usePBKDF2 and not useCryptExt:
     print("platform not supported")
