--- musicbrainz.py.orig	Tue Aug 17 08:44:54 2004
+++ musicbrainz.py	Sat Jan 14 14:04:01 2006
@@ -28,15 +28,7 @@
 Error = MusicBrainzError
 
 def findLibrary():
-    
-    if sys.platform == "darwin":
-        lib = "libmusicbrainz.4.dylib"
-    else:
-        if sys.platform == "linux2":
-           lib = "libmusicbrainz.so.4"
-        else:
-           raise MusicBrainzError, "Unknown platform: " + sys.platform 
-  
+    lib = "libmusicbrainz.so.4"
     path = "/usr/lib/" + lib
     if os.access(path, os.F_OK):
        return path;
