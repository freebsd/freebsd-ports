--- xcaplib/client.py.orig	2016-01-12 11:22:06 UTC
+++ xcaplib/client.py
@@ -175,7 +175,7 @@ class XCAPClient(XCAPClientBase):
         """
         try:
             self.get(application, **kwargs)
-        except HTTPError, ex:
+        except HTTPError as ex:
             if ex.status == 404:
                 # how to ensure insert?
                 # 1. make openxcap to supply fixed tag into 404, like ETag: "none"
@@ -203,13 +203,13 @@ class XCAPClient(XCAPClientBase):
             document = self.get(application, None, etag, **kwargs)
             try:
                 self.get(application, node, document.etag, **kwargs)
-            except HTTPError, ex:
+            except HTTPError as ex:
                 if etag is None and ex.status == 412:
                     continue
                 elif ex.status == 404:
                     try:
                         return self.put(application, resource, node, document.etag, **kwargs)
-                    except HTTPError, ex:
+                    except HTTPError as ex:
                         if etag is None and ex.status == 412:
                             continue
                         else:
