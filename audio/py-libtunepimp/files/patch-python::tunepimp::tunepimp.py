--- python/tunepimp/tunepimp.py.orig	Sat Jul  2 22:13:08 2005
+++ python/tunepimp/tunepimp.py	Fri Sep 16 22:44:39 2005
@@ -137,7 +137,16 @@
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
+                    if sys.platform == "freebsd4":
+                       lib = "libtunepimp.so.3"
+                    else:
+                        raise TunePimpError, "Unknown platform: " + sys.platform 
 
     pathList = [ ]
     ldLibPath = os.environ.get('LD_LIBRARY_PATH')
