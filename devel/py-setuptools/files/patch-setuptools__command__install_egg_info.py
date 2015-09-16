# install_egg_info command includes directory entries in --record output
# Issue: https://bitbucket.org/pypa/setuptools/issue/118
# TODO: Merge upstream (was merged, then backed out)

--- setuptools/command/install_egg_info.py.orig	2015-05-31 02:01:18 UTC
+++ setuptools/command/install_egg_info.py
@@ -27,7 +27,7 @@ class install_egg_info(Command):
         ).egg_name() + '.egg-info'
         self.source = ei_cmd.egg_info
         self.target = os.path.join(self.install_dir, basename)
-        self.outputs = [self.target]
+        self.outputs = []
 
     def run(self):
         self.run_command('egg_info')
