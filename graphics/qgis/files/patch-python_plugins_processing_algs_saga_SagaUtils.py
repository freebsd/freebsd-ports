--- python/plugins/processing/algs/saga/SagaUtils.py.orig	2017-10-27 12:00:21 UTC
+++ python/plugins/processing/algs/saga/SagaUtils.py
@@ -26,6 +26,7 @@ __copyright__ = '(C) 2012, Victor Olaya'
 __revision__ = '$Format:%H$'
 
 import os
+import platform
 import stat
 import subprocess
 import time
@@ -57,7 +58,7 @@ def sagaBatchJobFilename():
 
 def findSagaFolder():
     folder = None
-    if isMac():
+    if isMac() or platform.system() == 'FreeBSD':
         testfolder = os.path.join(QgsApplication.prefixPath(), 'bin')
         if os.path.exists(os.path.join(testfolder, 'saga_cmd')):
             folder = testfolder
@@ -82,7 +83,7 @@ def findSagaFolder():
 
 
 def sagaPath():
-    if not isWindows() and not isMac():
+    if not isWindows() and not isMac() and not platform.system() == 'FreeBSD':
         return ''
 
     folder = findSagaFolder()
@@ -101,7 +102,7 @@ def createSagaBatchJobFileFromSagaCommands(commands):
         fout.write('set SAGA_MLB=' + sagaPath() + os.sep +
                    'modules' + '\n')
         fout.write('PATH=%PATH%;%SAGA%;%SAGA_MLB%\n')
-    elif isMac():
+    elif isMac()  or platform.system() == 'FreeBSD':
         fout.write('export SAGA_MLB=' + sagaPath() +
                    '/../lib/saga\n')
         fout.write('export PATH=' + sagaPath() + ':$PATH\n')
@@ -130,7 +131,7 @@ def getSagaInstalledVersion(runSaga=False):
 
     if isWindows():
         commands = [os.path.join(sagaPath(), "saga_cmd.exe"), "-v"]
-    elif isMac():
+    elif isMac() or platform.system() == 'FreeBSD':
         commands = [os.path.join(sagaPath(), "saga_cmd -v")]
     else:
         # for Linux use just one string instead of separated parameters as the list
@@ -146,7 +147,7 @@ def getSagaInstalledVersion(runSaga=False):
             stderr=subprocess.STDOUT,
             universal_newlines=True,
         ).stdout
-        if isMac():  # This trick avoids having an uninterrupted system call exception if SAGA is not installed
+        if isMac() or platform.system() == 'FreeBSD':  # This trick avoids having an uninterrupted system call exception if SAGA is not installed
             time.sleep(1)
         try:
             lines = proc.readlines()
