--- setup/install.py.orig	2021-12-17 00:40:19 UTC
+++ setup/install.py
@@ -158,7 +158,7 @@ class Develop(Command):
         import sysconfig
         libdir = os.path.join(
             self.opts.staging_root, sysconfig.get_config_var('PLATLIBDIR') or 'lib',
-            sysconfig.get_python_version(), 'site-packages')
+            os.path.basename(sysconfig.get_config_var('DESTLIB') or sysconfig.get_config_var('LIBDEST') or f'python{sysconfig.get_python_version()}'), 'site-packages')
         try:
             if not os.path.exists(libdir):
                 os.makedirs(libdir)
