--- ArmoryQt.py.orig	2021-05-20 06:17:35 UTC
+++ ArmoryQt.py
@@ -1159,6 +1159,9 @@ class ArmoryMainWindow(QMainWindow):
          elif OS_LINUX:
             tempDir = '/var/log'
             extraFiles = ['/var/log/Xorg.0.log']
+         elif OS_FREEBSD:
+            tempDir = '/var/log'
+            extraFiles = ['/var/log/Xorg.0.log']
          elif OS_MACOSX:
             tempDir = '/var/log'
             extraFiles = ['/var/log/system.log']
@@ -3668,8 +3671,7 @@ class ArmoryMainWindow(QMainWindow):
    def closeExistingBitcoin(self):
       for proc in psutil.process_iter():
          try:
-            if proc.name().lower() in ['bitcoind.exe','bitcoin-qt.exe',\
-                                        'bitcoind','bitcoin-qt']:
+            if proc.name() in ['bitcoind','bitcoin-qt']:
                killProcess(proc.pid)
                time.sleep(2)
                return
