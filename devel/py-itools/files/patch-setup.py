--- setup.py.orig	2009-02-10 16:20:51.000000000 +0800
+++ setup.py	2009-02-10 16:21:04.000000000 +0800
@@ -21,7 +21,7 @@
 # Import from itools
 from utils import setup
 
-GLIB_INCLUDE_PATH = ['/usr/include/glib-2.0', '/usr/lib/glib-2.0/include/']
+GLIB_INCLUDE_PATH = ['/usr/local/include/glib-2.0', '/usr/lib/glib-2.0/include/']
 
 if __name__ == '__main__':
     cparser = Extension('itools.xml.parser',
