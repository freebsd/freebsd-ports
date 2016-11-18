--- install-i18n.py.orig	2013-08-19 13:16:47.862300000 +0400
+++ install-i18n.py	2013-10-05 17:55:20.162267518 +0400
@@ -1,4 +1,4 @@
-#!/usr/bin/env python3
+#!/usr/bin/env python
 # -*- coding: utf-8 -*-
 
 # Copyright (c) 2004 - 2015 Detlev Offenbach <detlev@die-offenbachs.de>
@@ -45,6 +45,7 @@
 # Define the globals.
 progName = None
 configDir = getConfigDir()
+distDir = None
 privateInstall = False
 
 def usage(rcode = 2):
@@ -71,7 +72,9 @@
     global privateInstall, configDir
     
     if privateInstall:
-        targetDir = configDir
+        targetDir = distDir + getConfig('ericTranslationsDir')
+        if not os.path.exists(targetDir):
+            os.makedirs(targetDir, 493) # 0o755
     else:
         targetDir = getConfig('ericTranslationsDir')
     
@@ -97,11 +100,12 @@
     progName = os.path.basename(argv[0])
 
     try:
-        optlist, args = getopt.getopt(argv[1:], "hp")
+        optlist, args = getopt.getopt(argv[1:], "hp:")
     except getopt.GetoptError:
         usage()
 
     global platBinDir
+    global distDir
     
     depChecks = 1
 
@@ -110,6 +114,7 @@
             usage(0)
         elif opt == "-p":
             privateInstall = 1
+            distDir = os.path.normpath(arg)
         
     installTranslations()
 
