--- install.py.orig	Tue Oct 19 19:34:17 2004
+++ install.py	Tue Oct 19 19:34:29 2004
@@ -231,10 +231,6 @@
                     'dataFilePath = None', \
                     'dataFilePath =  \'%s\'   # modified by install script\n' \
                     % dataPrefixDir)
-    if os.path.isdir('icons'):
-        iconBuildDir = os.path.join(buildRoot, prefixDir[1:], 'share', 'icons')
-        print '  Copying icon files to %s' % iconBuildDir
-        copyDir('icons', iconBuildDir)
     createWrapper(pythonPrefixDir, progName)
     binBuildDir = os.path.join(buildRoot, prefixDir[1:], 'bin')
     print '  Copying executable file "%s" to %s' % (progName, binBuildDir)
