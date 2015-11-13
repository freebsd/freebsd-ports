--- ArmoryQt.py.orig	2015-06-10 21:49:31 UTC
+++ ArmoryQt.py
@@ -1,4 +1,4 @@
-#! /usr/bin/python
+#!/usr/bin/env python
 # -*- coding: UTF-8 -*-
 ################################################################################
 #                                                                              #
@@ -1236,6 +1236,9 @@ class ArmoryMainWindow(QMainWindow):
          elif OS_LINUX:
             tempDir = '/var/log'
             extraFiles = ['/var/log/Xorg.0.log']
+         elif OS_FREEBSD:
+            tempDir = '/var/log'
+            extraFiles = ['/var/log/Xorg.0.log']
          elif OS_MACOSX:
             tempDir = '/var/log'
             extraFiles = ['/var/log/system.log']
@@ -1516,7 +1519,7 @@ class ArmoryMainWindow(QMainWindow):
       if USE_TESTNET:
          return
 
-      if OS_LINUX:
+      if OS_LINUX or OS_FREEBSD:
          out,err = execAndWait('gconftool-2 --get /desktop/gnome/url-handlers/bitcoin/command')
          out2,err = execAndWait('xdg-mime query default x-scheme-handler/bitcoin')
 
@@ -2104,6 +2107,8 @@ class ArmoryMainWindow(QMainWindow):
          shortOS = 'windows'
       elif OS_LINUX:
          shortOS = 'ubuntu'
+      elif OS_FREEBSD:
+         shortOS = 'freebsd'
       elif OS_MACOSX:
          shortOS = 'mac'
 
@@ -4570,6 +4575,8 @@ class ArmoryMainWindow(QMainWindow):
                Download and Install Bitcoin Core for Ubuntu/Debian"""))
             self.dashBtns[DASHBTNS.Install][TTIP] = self.createToolTipWidget( tr("""
                'Will download and Bitcoin software and cryptographically verify it"""))
+      elif OS_FREEBSD:
+         pass
       elif OS_MACOSX:
          pass
       else:
@@ -4970,8 +4977,7 @@ class ArmoryMainWindow(QMainWindow):
    def closeExistingBitcoin(self):
       for proc in psutil.process_iter():
          try:
-            if proc.name().lower() in ['bitcoind.exe','bitcoin-qt.exe',\
-                                        'bitcoind','bitcoin-qt']:
+            if proc.name() in ['bitcoind','bitcoin-qt']:
                killProcess(proc.pid)
                time.sleep(2)
                return
