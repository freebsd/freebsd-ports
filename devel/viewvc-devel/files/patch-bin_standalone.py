--- bin/standalone.py.orig	2025-07-22 12:12:06 UTC
+++ bin/standalone.py
@@ -191,18 +191,17 @@ class ViewVCHTTPRequestHandler(_http_server.BaseHTTPRe
 </html>"""
             )
 
-    def is_viewvc(self):
+    def is_viewvc(self, path):
         """Check whether self.path is, or is a child of, the ScriptAlias"""
+        if not path.startswith("/"):
+            return False
         if not options.script_alias:
-            return 1
-        if self.path == "/" + options.script_alias:
-            return 1
-        alias_len = len(options.script_alias)
-        if self.path[: (alias_len + 2)] == "/" + options.script_alias + "/":
-            return 1
-        if self.path[: (alias_len + 2)] == "/" + options.script_alias + "?":
-            return 1
-        return 0
+            return True
+        if path == "/" + options.script_alias:
+            return True
+        if path.startswith("/" + options.script_alias + "/"):
+            return True
+        return False
 
     def validate_password(self, htpasswd_file, username, password):
         """Compare USERNAME and PASSWORD against HTPASSWD_FILE."""
@@ -219,8 +218,18 @@ class ViewVCHTTPRequestHandler(_http_server.BaseHTTPRe
         # NOTE: Much of this is adapter from Python's standard library
         # module CGIHTTPServer.
 
+        i = self.path.rfind("?")
+        if i >= 0:
+            path = _unquote(self.path[:i], "utf-8", "surrogateescape")
+            query = self.path[(i + 1) :]
+        else:
+            path = _unquote(self.path)
+            query = ""
+        # normalize path
+        path = os.path.normpath(path) + ("/" if path[-1] == "/" else "")
+
         # Is this request even aimed at ViewVC?  If not, complain.
-        if not self.is_viewvc():
+        if not self.is_viewvc(path):
             raise NotViewVCLocationException()
 
         # If htpasswd authentication is enabled, try to authenticate the user.
@@ -245,12 +254,7 @@ class ViewVCHTTPRequestHandler(_http_server.BaseHTTPRe
 
         scriptname = options.script_alias and "/" + options.script_alias or ""
 
-        rest = self.path[len(scriptname) :]
-        i = rest.rfind("?")
-        if i >= 0:
-            rest, query = rest[:i], rest[(i + 1) :]
-        else:
-            query = ""
+        rest = path[len(scriptname) :]
 
         # Since we're going to modify the env in the parent, provide empty
         # values to override previously set values
@@ -274,8 +278,7 @@ class ViewVCHTTPRequestHandler(_http_server.BaseHTTPRe
         env["SERVER_PROTOCOL"] = self.protocol_version
         env["SERVER_PORT"] = str(self.server.server_port)
         env["REQUEST_METHOD"] = self.command
-        uqrest = _unquote(rest, "utf-8", "surrogateescape")
-        env["PATH_INFO"] = uqrest
+        env["PATH_INFO"] = rest
         env["SCRIPT_NAME"] = scriptname
         if query:
             env["QUERY_STRING"] = query
