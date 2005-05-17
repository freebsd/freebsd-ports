--- setup.py.orig	Sun May 15 10:11:47 2005
+++ setup.py	Sun May 15 10:12:02 2005
@@ -834,7 +834,7 @@
     #
     # This "autodetection" will probably work for some other Unixes as well.
     if not DATABASE_HOME_DIR:
-        DEFAULT_FREEBSD_HOME_DIR = '/usr/local/firebird'
+        DEFAULT_FREEBSD_HOME_DIR = '/usr/local'
         if os.path.isdir(DEFAULT_FREEBSD_HOME_DIR):
             DATABASE_HOME_DIR = DEFAULT_FREEBSD_HOME_DIR
             if not DATABASE_INCLUDE_DIR:
