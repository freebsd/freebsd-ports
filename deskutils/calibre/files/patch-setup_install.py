--- setup/install.py.orig	2023-12-15 00:57:56 UTC
+++ setup/install.py
@@ -358,29 +358,11 @@ class Bootstrap(Command):
 
     description = 'Bootstrap a fresh checkout of calibre from git to a state where it can be installed. Requires various development tools/libraries/headers'
     TRANSLATIONS_REPO = 'kovidgoyal/calibre-translations'
-    sub_commands = 'build iso639 iso3166 translations gui resources cacerts recent_uas'.split()
+    sub_commands = 'build iso639 iso3166 translations gui resources cacerts'.split()
 
     def add_options(self, parser):
         parser.add_option('--ephemeral', default=False, action='store_true',
             help='Do not download all history for the translations. Speeds up first time download but subsequent downloads will be slower.')
-
-    def pre_sub_commands(self, opts):
-        tdir = self.j(self.d(self.SRC), 'translations')
-        clone_cmd = [
-            'git', 'clone', f'https://github.com/{self.TRANSLATIONS_REPO}.git', 'translations']
-        if opts.ephemeral:
-            if os.path.exists(tdir):
-                shutil.rmtree(tdir)
-
-            st = time.time()
-            clone_cmd.insert(2, '--depth=1')
-            subprocess.check_call(clone_cmd, cwd=self.d(self.SRC))
-            print('Downloaded translations in %d seconds' % int(time.time() - st))
-        else:
-            if os.path.exists(tdir):
-                subprocess.check_call(['git', 'pull'], cwd=tdir)
-            else:
-                subprocess.check_call(clone_cmd, cwd=self.d(self.SRC))
 
     def run(self, opts):
         self.info('\n\nAll done! You should now be able to run "%s setup.py install" to install calibre' % sys.executable)
