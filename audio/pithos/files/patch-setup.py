--- ./setup.py.orig	2011-12-14 16:33:47.000000000 -0800
+++ ./setup.py	2012-04-16 10:58:58.477390915 -0700
@@ -17,67 +17,19 @@
 
 ###################### DO NOT TOUCH THIS (HEAD TO THE SECOND PART) ######################
 
-try:
-    import DistUtilsExtra.auto
-except ImportError:
-    import sys
-    print >> sys.stderr, 'To build pithos you need https://launchpad.net/python-distutils-extra'
-    sys.exit(1)
-
-assert DistUtilsExtra.auto.__version__ >= '2.10', 'needs DistUtilsExtra.auto >= 2.10'
+import sys
 import os
+from distutils.core import setup
 
-
-def update_data_path(prefix, oldvalue=None):
-
-    try:
-        fin = file('pithos/pithosconfig.py', 'r')
-        fout = file(fin.name + '.new', 'w')
-
-        for line in fin:            
-            fields = line.split(' = ') # Separate variable from value
-            if fields[0] == '__pithos_data_directory__':
-                # update to prefix, store oldvalue
-                if not oldvalue:
-                    oldvalue = fields[1]
-                    line = "%s = '%s'\n" % (fields[0], prefix)
-                else: # restore oldvalue
-                    line = "%s = %s" % (fields[0], oldvalue)
-            fout.write(line)
-
-        fout.flush()
-        fout.close()
-        fin.close()
-        os.rename(fout.name, fin.name)
-    except (OSError, IOError), e:
-        print ("ERROR: Can't find pithos/pithosconfig.py")
-        sys.exit(1)
-    return oldvalue
-
-
-class InstallAndUpdateDataDirectory(DistUtilsExtra.auto.install_auto):
-    def run(self):
-        if self.root or self.home:
-            print "WARNING: You don't use a standard --prefix installation, take care that you eventually " \
-            "need to update quickly/quicklyconfig.py file to adjust __quickly_data_directory__. You can " \
-            "ignore this warning if you are packaging and uses --prefix."
-        previous_value = update_data_path(self.prefix + '/share/pithos/')
-        DistUtilsExtra.auto.install_auto.run(self)
-        update_data_path(self.prefix, previous_value)
-
-from DistUtilsExtra.command.build_extra import build_extra
-from DistUtilsExtra.command.build_icons import build_icons
-
-DistUtilsExtra.auto.setup(
+required = []
+setup(
     name='pithos',
-    version='0.3',
-    ext_modules=[],
-    license='GPL-3',
+    version='0.3.14',
+    description='Pandora.com client for the GNOME desktop',
     author='Kevin Mehall',
     author_email='km@kevinmehall.net',
-    description='Pandora.com client for the GNOME desktop',
-    #long_description='Here a longer description',
     url='https://launchpad.net/pithos',
-    cmdclass={'install': InstallAndUpdateDataDirectory, 'build_icons':build_icons, 'build':build_extra}
-    )
-
+    license='GPL-3',
+    packages=['pithos', 'pithos.pandora', 'pithos.plugins'],
+    package_dir = {'pithos':'pithos'}
+)
