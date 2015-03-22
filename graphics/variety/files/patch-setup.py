--- setup.py.orig	2015-02-08 18:03:27 UTC
+++ setup.py
@@ -60,7 +60,10 @@ def update_desktop_file(datadir):
 
         for line in fin:            
             if 'Icon=' in line:
-                line = "Icon=%s\n" % (datadir + 'media/variety.svg')
+                line = "Icon=%s\n" % (datadir + '/share/variety/media/variety.svg')
+            if 'Exec=/opt' in line:
+                cmd, arg = line.split()
+                line = "Exec=%s %s\n" % (datadir + '/bin/variety', arg)
             fout.write(line)
         fout.flush()
         fout.close()
@@ -76,7 +79,7 @@ class InstallAndUpdateDataDirectory(Dist
         values = {'__variety_data_directory__': "'%s'" % (self.prefix + '/share/variety/'),
                   '__version__': "'%s'" % self.distribution.get_version()}
         previous_values = update_config(values)
-        update_desktop_file(self.prefix + '/share/variety/')
+        update_desktop_file(self.prefix)
         DistUtilsExtra.auto.install_auto.run(self)
         update_config(previous_values)
 
