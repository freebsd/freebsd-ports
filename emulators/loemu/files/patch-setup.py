--- setup.py.orig	2008-02-21 22:23:10 UTC
+++ setup.py
@@ -7,21 +7,6 @@ import sys
 if sys.hexversion < 0x020400f0:
     sys.stderr.write("python version failed: current version = %s.%s, needed version >= 2.4\n" % (sys.version_info[0],sys.version_info[1]))
     sys.exit(1)
-try:
-    import libxml2
-except ImportError:
-    sys.stderr.write("dependencies failed: python libxml2\n") 
-    sys.exit(1)
-try:
-    import libxslt
-except ImportError:
-    sys.stderr.write("dependencies failed: python libxslt1\n") 
-    sys.exit(1)
-try:
-    import gtk.glade
-except ImportError:
-    sys.stderr.write("dependencies failed: python glade\n") 
-    sys.exit(1)
 
 # make sure that the mo files are generated and up-to-date
 os.system("cd po; make update-po")
