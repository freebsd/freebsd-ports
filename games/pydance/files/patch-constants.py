--- constants.py.orig	Wed Feb 25 20:18:19 2004
+++ constants.py	Wed Feb 25 23:21:46 2004
@@ -13,7 +13,7 @@
 from pygame.locals import *
 
 VERSION = "0.9.1"
-locale.setlocale(locale.LC_ALL, '')
+locale.setlocale(locale.LC_ALL, 'C')
 
 # Detect the name of the OS - Mac OS X is not really UNIX.
 osname = None
