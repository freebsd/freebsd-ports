--- ArmoryQt.py
+++ ArmoryQt.py
@@ -1,4 +1,4 @@
-#! /usr/bin/python
+#!/usr/bin/env python
 ################################################################################
 #                                                                              #
 # Copyright (C) 2011-2014, Armory Technologies, Inc.                           #
@@ -1089,6 +1089,9 @@
          elif OS_LINUX:
             tempDir = '/var/log'
             extraFiles = ['/var/log/Xorg.0.log']
+         elif OS_FREEBSD:
+            tempDir = '/var/log'
+            extraFiles = ['/var/log/Xorg.0.log']
          elif OS_MACOSX:
             tempDir = '/var/log'
             extraFiles = ['/var/log/system.log']
@@ -1369,7 +1372,7 @@
       if USE_TESTNET:
          return
 
-      if OS_LINUX:
+      if OS_LINUX or OS_FREEBSD:
          out,err = execAndWait('gconftool-2 --get /desktop/gnome/url-handlers/bitcoin/command')
          out2,err = execAndWait('xdg-mime query default x-scheme-handler/bitcoin')
 
@@ -1890,6 +1893,8 @@
          shortOS = 'windows'
       elif OS_LINUX:
          shortOS = 'ubuntu'
+      elif OS_FREEBSD:
+         shortOS = 'freebsd'
       elif OS_MACOSX:
          shortOS = 'mac'
 
@@ -4708,6 +4713,8 @@
                'Will download and Bitcoin software and cryptographically verify it"""))
       elif OS_MACOSX:
          pass
+      elif OS_FREEBSD:
+         pass
       else:
          LOGERROR('Unrecognized OS!')
 
@@ -5101,8 +5108,7 @@
    #############################################################################
    def closeExistingBitcoin(self):
       for proc in psutil.process_iter():
-         if proc.name.lower() in ['bitcoind.exe','bitcoin-qt.exe',\
-                                     'bitcoind','bitcoin-qt']:
+         if proc.name() in ['bitcoind','bitcoin-qt']:
             killProcess(proc.pid)
             time.sleep(2)
             return
