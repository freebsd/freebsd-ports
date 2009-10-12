--- src/calibre/linux.py.orig	2009-10-10 06:15:01.000000000 +0400
+++ src/calibre/linux.py	2009-10-12 14:10:34.000000000 +0400
@@ -128,10 +128,7 @@
         self.icon_resources = []
         self.menu_resources = []
         self.mime_resources = []
-        self.setup_completion()
-        self.setup_udev_rules()
         self.install_man_pages()
-        self.setup_desktop_integration()
         self.create_uninstaller()
 
         from calibre.utils.config import config_dir
@@ -140,8 +137,6 @@
             for f in os.listdir('.'):
                 if os.stat(f).st_uid == 0:
                     os.rmdir(f) if os.path.isdir(f) else os.unlink(f)
-        if os.stat(config_dir).st_uid == 0:
-            os.rmdir(config_dir)
 
         if warn is None and self.warnings:
             self.info('There were %d warnings'%len(self.warnings))
@@ -319,7 +314,7 @@
     def install_man_pages(self):
         try:
             from calibre.utils.help2man import create_man_page
-            manpath = os.path.join(self.opts.staging_sharedir, 'man/man1')
+            manpath = os.path.join(self.opts.staging_root, 'man/man1')
             if not os.path.exists(manpath):
                 os.makedirs(manpath)
             self.info('Installing MAN pages...')
@@ -332,7 +327,7 @@
                     continue
                 parser = parser()
                 raw = create_man_page(prog, parser)
-                manfile = os.path.join(manpath, prog+'.1'+__appname__+'.bz2')
+                manfile = os.path.join(manpath, prog+'.1')
                 self.info('\tInstalling MAN page for', prog)
                 open(manfile, 'wb').write(raw)
                 self.manifest.append(manfile)
