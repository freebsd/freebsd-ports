--- install.py.orig	Wed Jul  7 19:59:06 2004
+++ install.py	Wed Jul  7 19:59:19 2004
@@ -247,10 +247,6 @@
                     'dataFilePath = None', \
                     'dataFilePath =  \'%s\'   # modified by install script\n' \
                     % dataDir)
-    if os.path.isdir('icons'):
-        iconDir = os.path.join(prefixDir, 'share', 'icons')
-        print '  Copying icon files to %s' % iconDir
-        copyDir('icons', iconDir)
     if siteCustomReqd:
         createSiteCustomize()
     createWrapper(pyDir, progName)
