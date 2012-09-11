--- ./ninja_ide/core/filesystem_notifications/__init__.py.orig	2012-08-23 01:57:46.000000000 +0200
+++ ./ninja_ide/core/filesystem_notifications/__init__.py	2012-09-11 10:45:02.000000000 +0200
@@ -23,7 +23,7 @@
 if sys.platform == 'win32':
     from ninja_ide.core.filesystem_notifications import windows
     source = windows
-elif sys.platform == 'darwin':
+elif sys.platform == 'darwin' or sys.platform.startswith('freebsd'):
     from ninja_ide.core.filesystem_notifications import darwin
     source = darwin
 else:
