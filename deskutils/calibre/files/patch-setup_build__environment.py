--- setup/build_environment.py.orig	2017-06-16 04:00:12 UTC
+++ setup/build_environment.py
@@ -84,7 +84,7 @@ pyqt['sip_bin'] = os.environ.get('SIP_BIN', 'sip')
 from PyQt5.QtCore import PYQT_CONFIGURATION
 pyqt['sip_flags'] = PYQT_CONFIGURATION['sip_flags']
 def get_sip_dir():
-    q = os.environ.get('SIP_DIR', os.path.join(sys.prefix, 'share', 'sip') if iswindows else os.path.join(sys.prefix, 'share', 'sip'))
+    q = os.environ.get('SIP_DIR', os.path.join(sys.prefix, 'share', 'sip') if iswindows else os.path.join(sys.prefix, 'share', 'py-sip'))
     for x in ('', 'Py2-PyQt5', 'PyQt5', 'sip/PyQt5'):
         base = os.path.join(q, x)
         if os.path.exists(os.path.join(base, 'QtWidgets')):
