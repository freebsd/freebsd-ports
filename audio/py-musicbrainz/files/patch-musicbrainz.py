--- musicbrainz.py.orig	Tue Aug 17 03:44:32 2004
+++ musicbrainz.py	Sat Aug 20 13:57:38 2005
@@ -35,7 +35,13 @@
         if sys.platform == "linux2":
            lib = "libmusicbrainz.so.4"
         else:
-           raise MusicBrainzError, "Unknown platform: " + sys.platform 
+            if sys.platform == "freebsd5":
+               lib = "libmusicbrainz.so.4"
+            else:
+                if sys.platform == "freebsd6":
+                   lib = "libmusicbrainz.so.4"
+                else:
+                    raise MusicBrainzError, "Unknown platform: " + sys.platform 
   
     path = "/usr/lib/" + lib
     if os.access(path, os.F_OK):
