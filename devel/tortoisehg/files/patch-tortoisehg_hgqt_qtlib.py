--- tortoisehg/hgqt/qtlib.py.orig	2018-11-19 10:53:15 UTC
+++ tortoisehg/hgqt/qtlib.py
@@ -1470,5 +1470,3 @@ class PaletteSwitcher(object):
 def setContextMenuShortcut(action, shortcut):
     """Set shortcut for a context menu action, making sure it's visible"""
     action.setShortcut(shortcut)
-    if QT_VERSION >= 0x50a00:
-        action.setShortcutVisibleInContextMenu(True)
