--- bugzilla/_session.py
+++ bugzilla/_session.py
@@ -98,14 +98,14 @@ def request(self, *args, **kwargs):
         if "timeout" not in kwargs:
             kwargs["timeout"] = timeout
 
-        response = self._session.request(*args, **kwargs)
+        try:
+            response = self._session.request(*args, **kwargs)
 
-        if self._is_xmlrpc:
-            # Yes this still appears to matter for properly decoding unicode
-            # code points in bugzilla.redhat.com content
-            response.encoding = "UTF-8"
+            if self._is_xmlrpc:
+                # This still appears to matter for properly decoding unicode
+                # code points in bugzilla.redhat.com content
+                response.encoding = "UTF-8"
 
-        try:
             response.raise_for_status()
         except requests.HTTPError as e:
             # Scrape the api key out of the returned exception string
