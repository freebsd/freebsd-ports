--- python/tunepimp/tunepimp.py.orig	Sat Aug 20 13:53:49 2005
+++ python/tunepimp/tunepimp.py	Sat Aug 20 13:54:58 2005
@@ -137,7 +137,13 @@
         if sys.platform == "linux2":
            lib = "libtunepimp.so.3"
         else:
-           raise TunePimpError, "Unknown platform: " + sys.platform 
+            if sys.platform == "freebsd5":
+               lib = "libtunepimp.so.3"
+            else:
+                if sys.platform == "freebsd6":
+                   lib = "libtunepimp.so.3"
+                else:
+                    raise TunePimpError, "Unknown platform: " + sys.platform 
 
     pathList = [ ]
     ldLibPath = os.environ.get('LD_LIBRARY_PATH')
