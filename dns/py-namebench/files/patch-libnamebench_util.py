--- libnamebench/util.py.orig	2016-11-04 16:13:39 UTC
+++ libnamebench/util.py
@@ -85,7 +85,7 @@ def FindDataFile(filename):
                   os.path.join(os.getcwd(), 'namebench.app', 'Contents', 'Resources'),
                   os.path.join(os.getcwd(), '..'),
                   os.path.join(sys.prefix, 'namebench'),
-                  '/usr/local/share/namebench'
+                  '/usr/local/share/namebench',
                   '/usr/local/etc/namebench',
                   '/usr/local/namebench',
                   '/etc/namebench',
