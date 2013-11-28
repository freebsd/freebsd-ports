--- setuptools/command/install_egg_info.py.orig	2013-11-27 22:45:15.000000000 +0100
+++ setuptools/command/install_egg_info.py	2013-11-27 22:45:23.000000000 +0100
@@ -23,7 +23,7 @@
         ).egg_name()+'.egg-info'
         self.source = ei_cmd.egg_info
         self.target = os.path.join(self.install_dir, basename)
-        self.outputs = [self.target]
+        self.outputs = []
 
     def run(self):
         self.run_command('egg_info')
