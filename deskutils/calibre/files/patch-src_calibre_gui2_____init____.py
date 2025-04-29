--- src/calibre/gui2/__init__.py.orig	2025-04-18 03:14:01 UTC
+++ src/calibre/gui2/__init__.py
@@ -1619,6 +1619,8 @@ def ensure_app(headless=True):
             has_headless = ismacos or islinux or isbsd
             if headless and has_headless:
                 args += ['-platformpluginpath', plugins_loc, '-platform', os.environ.get('CALIBRE_HEADLESS_PLATFORM', 'headless')]
+                if isbsd:
+                    os.environ['QTWEBENGINE_CHROMIUM_FLAGS'] = '--disable-gpu'
                 if ismacos:
                     os.environ['QT_MAC_DISABLE_FOREGROUND_APPLICATION_TRANSFORM'] = '1'
             if headless and iswindows:
