--- lib/viewvc.py.orig	2025-07-22 12:12:06 UTC
+++ lib/viewvc.py
@@ -193,6 +193,10 @@ class Request:
         # TODO: we might want to redirect to the cleaned up URL
         path_parts = _path_parts(path_info)
 
+        # Protect against directory traversal attacks.
+        if ".." in path_parts:
+            raise ViewVCException("An illegal path was provided.", "400 Bad Request")
+
         if path_parts:
             # handle docroot magic path prefixes
             if path_parts[0] == docroot_magic_path:
@@ -3401,10 +3405,8 @@ def view_doc(request):
     # Stat the file to get content length and last-modified date.
     try:
         info = os.stat(filename)
-    except OSError as v:
-        raise ViewVCException(
-            'Static file "%s" not available (%s)' % (document, str(v)), "404 Not Found"
-        )
+    except OSError:
+        raise ViewVCException('Static file "%s" not available' % (document), "404 Not Found")
     content_length = str(info[stat.ST_SIZE])
     last_modified = info[stat.ST_MTIME]
 
@@ -3414,10 +3416,8 @@ def view_doc(request):
 
     try:
         fp = open(filename, "rb")
-    except IOError as v:
-        raise ViewVCException(
-            'Static file "%s" not available (%s)' % (document, str(v)), "404 Not Found"
-        )
+    except IOError:
+        raise ViewVCException('Static file "%s" not available' % (document), "404 Not Found")
 
     if document[-3:] == "png":
         mime_type = "image/png"
