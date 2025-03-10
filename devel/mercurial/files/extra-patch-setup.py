--- setup.py.orig	2024-11-20 14:38:51 UTC
+++ setup.py
@@ -527,39 +527,7 @@ class hgbuildmo(build):
             raise DistutilsExecError("failed to build translations")
 
     def _run(self):
-        try:
-            from shutil import which as find_executable
-        except ImportError:
-            # Deprecated in py3.12
-            from distutils.spawn import find_executable
-
-        if not find_executable('msgfmt'):
-            self.warn(
-                "could not find msgfmt executable, no translations "
-                "will be built"
-            )
-            return False
-
-        podir = 'i18n'
-        if not os.path.isdir(podir):
-            self.warn("could not find %s/ directory" % podir)
-            return False
-
-        join = os.path.join
-        for po in os.listdir(podir):
-            if not po.endswith('.po'):
-                continue
-            pofile = join(podir, po)
-            modir = join('locale', po[:-3], 'LC_MESSAGES')
-            mofile = join(modir, 'hg.mo')
-            mobuildfile = join('mercurial', mofile)
-            cmd = ['msgfmt', '-v', '-o', mobuildfile, pofile]
-            if sys.platform != 'sunos5':
-                # msgfmt on Solaris does not know about -c
-                cmd.append('-c')
-            self.mkpath(join('mercurial', modir))
-            self.make_file([pofile], mobuildfile, spawn, (cmd,))
-        return True
+        pass
 
 
 class hgdist(Distribution):
