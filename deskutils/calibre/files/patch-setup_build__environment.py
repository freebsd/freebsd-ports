--- setup/build_environment.py.orig	2016-06-24 01:54:27 UTC
+++ setup/build_environment.py
@@ -98,7 +98,7 @@ pyqt['sip_bin'] = os.environ.get('SIP_BI
 from PyQt5.QtCore import PYQT_CONFIGURATION
 pyqt['sip_flags'] = PYQT_CONFIGURATION['sip_flags']
 def get_sip_dir():
-    q = os.environ.get('SIP_DIR', sys.prefix if iswindows else os.path.join(sys.prefix, 'share', 'sip'))
+    q = os.environ.get('SIP_DIR', sys.prefix if iswindows else os.path.join(sys.prefix, 'share', 'py-sip'))
     for x in ('', 'Py2-PyQt5', 'PyQt5', 'sip/PyQt5'):
         base = os.path.join(q, x)
         if os.path.exists(os.path.join(base, 'QtWidgets')):
