--- setup/build_environment.py.orig	2015-02-20 03:34:13 UTC
+++ setup/build_environment.py
@@ -101,7 +101,7 @@ def get_sip_dir(q):
         if os.path.exists(os.path.join(base, 'QtWidgets')):
             return base
     raise EnvironmentError('Failed to find the location of the PyQt5 .sip files')
-pyqt['pyqt_sip_dir'] = get_sip_dir(sys.prefix if iswindows else os.path.join(sys.prefix, 'share', 'sip'))
+pyqt['pyqt_sip_dir'] = get_sip_dir(sys.prefix if iswindows else os.path.join(sys.prefix, 'share', 'py-sip'))
 pyqt['sip_inc_dir'] = sysconfig.get_path('include')
 
 glib_flags = subprocess.check_output([PKGCONFIG, '--libs', 'glib-2.0']).strip() if islinux else ''
