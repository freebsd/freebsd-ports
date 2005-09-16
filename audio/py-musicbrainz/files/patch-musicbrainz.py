--- musicbrainz.py.orig	Tue Aug 17 03:44:32 2004
+++ musicbrainz.py	Fri Sep 16 19:14:15 2005
@@ -35,7 +35,16 @@
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
+                   if sys.platform == "freebsd4":
+                      lib = "libmusicbrainz.so.4"
+                   else:
+                      raise MusicBrainzError, "Unknown platform: " + sys.platform 
   
     path = "/usr/lib/" + lib
     if os.access(path, os.F_OK):
