--- ./setup.py.orig	2012-10-02 04:11:23.000000000 +0000
+++ ./setup.py	2012-10-02 18:59:20.000000000 +0000
@@ -227,30 +227,7 @@
     description = "build translations (.mo files)"
 
     def run(self):
-        if not find_executable('msgfmt'):
-            self.warn("could not find msgfmt executable, no translations "
-                     "will be built")
-            return
-
-        podir = 'i18n'
-        if not os.path.isdir(podir):
-            self.warn("could not find %s/ directory" % podir)
-            return
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
+        pass
 
 
 class hgdist(Distribution):
