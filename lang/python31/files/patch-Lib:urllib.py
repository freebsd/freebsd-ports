--- Lib/urllib.py.orig	Wed Apr 10 08:19:21 2002
+++ Lib/urllib.py	Wed Apr 10 08:25:58 2002
@@ -409,7 +409,10 @@
         import mimetypes, mimetools, rfc822, StringIO
         host, file = splithost(url)
         localname = url2pathname(file)
-        stats = os.stat(localname)
+        try:
+            stats = os.stat(localname)
+        except OSError, e:
+            raise IOError(e.errno, e.strerror, e.filename)
         size = stats[stat.ST_SIZE]
         modified = rfc822.formatdate(stats[stat.ST_MTIME])
         mtype = mimetypes.guess_type(url)[0]
