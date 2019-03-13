--- python/plugins/processing/algs/saga/SagaUtils.py.orig	2018-11-23 12:08:36 UTC
+++ python/plugins/processing/algs/saga/SagaUtils.py
@@ -26,6 +26,7 @@ __copyright__ = '(C) 2012, Victor Olaya'
 __revision__ = '564579199220ae06abd248f0dc80b7ff57b80128'
 
 import os
+import platform
 import stat
 import subprocess
 import time
@@ -59,7 +60,7 @@ def sagaBatchJobFilename():
 
 def findSagaFolder():
     folder = None
-    if isMac():
+    if isMac() or platform.system() == 'FreeBSD':
         testfolder = os.path.join(QgsApplication.prefixPath(), 'bin')
         if os.path.exists(os.path.join(testfolder, 'saga_cmd')):
             folder = testfolder
@@ -84,7 +85,7 @@ def findSagaFolder():
 
 
 def sagaPath():
-    if not isWindows() and not isMac():
+    if not isWindows() and not isMac() and not platform.system() == 'FreeBSD':
         return ''
 
     folder = findSagaFolder()
@@ -102,7 +103,7 @@ def createSagaBatchJobFileFromSagaCommands(commands):
             fout.write('set SAGA=' + sagaPath() + '\n')
             fout.write('set SAGA_MLB=' + os.path.join(sagaPath(), 'modules') + '\n')
             fout.write('PATH=%PATH%;%SAGA%;%SAGA_MLB%\n')
-        elif isMac():
+        elif isMac() or platform.system() == 'FreeBSD':
             fout.write('export SAGA_MLB=' + os.path.join(sagaPath(), '../lib/saga') + '\n')
             fout.write('export PATH=' + sagaPath() + ':$PATH\n')
         else:
@@ -129,7 +130,7 @@ def getInstalledVersion(runSaga=False):
 
     if isWindows():
         commands = [os.path.join(sagaPath(), "saga_cmd.exe"), "-v"]
-    elif isMac():
+    elif isMac() or platform.system() == 'FreeBSD':
         commands = [os.path.join(sagaPath(), "saga_cmd -v")]
     else:
         # for Linux use just one string instead of separated parameters as the list
@@ -145,7 +146,7 @@ def getInstalledVersion(runSaga=False):
             stderr=subprocess.STDOUT,
             universal_newlines=True,
         ) as proc:
-            if isMac():  # This trick avoids having an uninterrupted system call exception if SAGA is not installed
+            if isMac() or platform.system() == 'FreeBSD':  # This trick avoids having an uninterrupted system call exception if SAGA is not installed
                 time.sleep(1)
             try:
                 lines = proc.stdout.readlines()
