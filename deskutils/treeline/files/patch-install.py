--- install.py.orig	Thu Sep  2 10:31:10 2004
+++ install.py	Thu Sep  2 10:31:35 2004
@@ -257,10 +257,6 @@
                     'dataFilePath = None', \
                     'dataFilePath =  \'%s\'   # modified by install script\n' \
                     % dataPrefixDir)
-    if os.path.isdir('icons'):
-        iconBuildDir = os.path.join(buildRoot, prefixDir[1:], 'share', 'icons')
-        print '  Copying icon files to %s' % iconBuildDir
-        copyDir('icons', iconBuildDir)
     if siteCustomReqd:
         createSiteCustomize(siteCustomExt)
     createWrapper(pythonPrefixDir, progName)
