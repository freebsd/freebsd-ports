--- setup.py.orig	2010-08-07 22:10:05.426837040 -0500
+++ setup.py	2010-08-07 22:10:51.941435450 -0500
@@ -727,7 +727,7 @@
         # easy_install one
         DATA_FILES = [('man/man1', ['bzr.1'])]
 
-    if sys.platform != 'win32':
+    if 0:
         # see https://wiki.kubuntu.org/Apport/DeveloperHowTo
         #
         # checking the paths and hardcoding the check for root is a bit gross,
