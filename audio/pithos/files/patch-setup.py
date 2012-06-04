--- setup.py	2012-05-03 13:47:11.000000000 -0700
+++ setup.py	2012-06-01 11:40:31.000000000 -0700
@@ -17,74 +17,19 @@
 
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
-from distutils.cmd import Command    
-class OverrideI18NCommand(Command):
-	def initialize_options(self): pass
-	def finalize_options(self): pass
-	def run(self):
-		self.distribution.data_files.append(('share/applications', ['pithos.desktop']))
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
+    version='0.3.17',
     license='GPL-3',
     author='Kevin Mehall',
     author_email='km@kevinmehall.net',
     description='Pandora.com client for the GNOME desktop',
-    #long_description='Here a longer description',
     url='https://launchpad.net/pithos',
-    cmdclass={'install': InstallAndUpdateDataDirectory, 'build_icons':build_icons, 'build':build_extra, 'build_i18n':OverrideI18NCommand}
-    )
-
+    packages=['pithos', 'pithos.pandora', 'pithos.plugins'],
+    package_dir = {'pithos':'pithos'}
+)
