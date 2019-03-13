--- cmake/FindPyQt5.py.orig	2019-01-02 08:42:18 UTC
+++ cmake/FindPyQt5.py
@@ -54,7 +54,7 @@ except ImportError:
         'pyqt_version_str': PyQt5.QtCore.PYQT_VERSION_STR,
         'pyqt_sip_flags': PyQt5.QtCore.PYQT_CONFIGURATION['sip_flags'],
         'pyqt_mod_dir': os.path.join(cfg.default_mod_dir, "PyQt5"),
-        'pyqt_sip_dir': sip_dir,
+        'pyqt_sip_dir': sip_dir.replace('PyQtsip', 'PyQt5'),
         'pyqt_bin_dir': cfg.default_bin_dir,
     }
     pyqtcfg = sipconfig.Configuration([cfg])
