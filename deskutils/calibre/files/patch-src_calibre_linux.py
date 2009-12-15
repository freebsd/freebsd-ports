--- src/calibre/linux.py.orig	2009-12-11 15:04:41.000000000 -0800
+++ src/calibre/linux.py	2009-12-14 17:29:52.000000000 -0800
@@ -128,20 +128,12 @@
         self.icon_resources = []
         self.menu_resources = []
         self.mime_resources = []
-        self.setup_completion()
-        self.setup_udev_rules()
         self.install_man_pages()
-        self.setup_desktop_integration()
         self.create_uninstaller()
 
         from calibre.utils.config import config_dir
         if os.path.exists(config_dir):
             os.chdir(config_dir)
-            for f in os.listdir('.'):
-                if os.stat(f).st_uid == 0:
-                    os.rmdir(f) if os.path.isdir(f) else os.unlink(f)
-            if os.stat(config_dir).st_uid == 0:
-                os.rmdir(config_dir)
 
         if warn is None and self.warnings:
             self.info('There were %d warnings'%len(self.warnings))
@@ -318,7 +310,7 @@
     def install_man_pages(self):
         try:
             from calibre.utils.help2man import create_man_page
-            manpath = os.path.join(self.opts.staging_sharedir, 'man/man1')
+            manpath = os.path.join(self.opts.staging_root, 'man/man1')
             if not os.path.exists(manpath):
                 os.makedirs(manpath)
             self.info('Installing MAN pages...')
@@ -331,7 +323,7 @@
                     continue
                 parser = parser()
                 raw = create_man_page(prog, parser)
-                manfile = os.path.join(manpath, prog+'.1'+__appname__+'.bz2')
+                manfile = os.path.join(manpath, prog+'.1')
                 self.info('\tInstalling MAN page for', prog)
                 open(manfile, 'wb').write(raw)
                 self.manifest.append(manfile)
