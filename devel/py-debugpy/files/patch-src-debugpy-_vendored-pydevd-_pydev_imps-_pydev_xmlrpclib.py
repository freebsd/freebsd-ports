--- src/debugpy/_vendored/pydevd/_pydev_imps/_pydev_xmlrpclib.py.orig	2022-01-15 23:38:41 UTC
+++ src/debugpy/_vendored/pydevd/_pydev_imps/_pydev_xmlrpclib.py
@@ -146,9 +146,9 @@ from types import *
 # Internal stuff
 
 try:
-    unicode
+    str
 except NameError:
-    unicode = None # unicode support not available
+    str = None # unicode support not available
 
 try:
     import datetime
@@ -162,8 +162,8 @@ except (NameError, AttributeError):
 
 def _decode(data, encoding, is8bit=re.compile("[\x80-\xff]").search):
     # decode non-ascii string (if possible)
-    if unicode and encoding and is8bit(data):
-        data = unicode(data, encoding)
+    if str and encoding and is8bit(data):
+        data = str(data, encoding)
     return data
 
 def escape(s, replace=string.replace):
@@ -171,7 +171,7 @@ def escape(s, replace=string.replace):
     s = replace(s, "<", "&lt;")
     return replace(s, ">", "&gt;",)
 
-if unicode:
+if str:
     def _stringify(string):
         # convert to 7-bit ascii if possible
         try:
@@ -186,11 +186,11 @@ __version__ = "1.0.1"
 
 # xmlrpc integer limits
 try:
-    long 
+    int 
 except NameError:
     long = int
-MAXINT = long(2) ** 31 - 1
-MININT = long(-2) ** 31
+MAXINT = int(2) ** 31 - 1
+MININT = int(-2) ** 31
 
 # --------------------------------------------------------------------
 # Error constants (from Dan Libby's specification at
@@ -291,7 +291,6 @@ class Fault(Error):
 if _bool_is_builtin:
     boolean = Boolean = bool #@UndefinedVariable
     # to avoid breaking code which references xmlrpclib.{True,False}
-    True, False = True, False
 else:
     class Boolean:
         """Boolean-value wrapper.
@@ -319,11 +318,9 @@ else:
         def __int__(self):
             return self.value
 
-        def __nonzero__(self):
+        def __bool__(self):
             return self.value
 
-    True, False = Boolean(1), Boolean(0)
-
     ##
     # Map true or false value to XML-RPC boolean values.
     #
@@ -420,9 +417,9 @@ def _datetime_type(data):
 
 import base64
 try:
-    import cStringIO as StringIO
+    import io as StringIO
 except ImportError:
-    import StringIO
+    import io
 
 class Binary:
     """Wrapper for binary data."""
@@ -448,7 +445,7 @@ class Binary:
 
     def encode(self, out):
         out.write("<value><base64>\n")
-        base64.encode(StringIO.StringIO(self.data), out)
+        base64.encode(io.StringIO(self.data), out)
         out.write("</base64></value>\n")
 
 def _binary(data):
@@ -682,7 +679,7 @@ class Marshaller:
         write("</string></value>\n")
     dispatch[StringType] = dump_string
 
-    if unicode:
+    if str:
         def dump_unicode(self, value, write, escape=escape):
             value = value.encode(self.encoding)
             write("<value><string>")
@@ -692,7 +689,7 @@ class Marshaller:
 
     def dump_array(self, value, write):
         i = id(value)
-        if self.memo.has_key(i):
+        if i in self.memo:
             raise TypeError("cannot marshal recursive sequences")
         self.memo[i] = None
         dump = self.__dump
@@ -706,15 +703,15 @@ class Marshaller:
 
     def dump_struct(self, value, write, escape=escape):
         i = id(value)
-        if self.memo.has_key(i):
+        if i in self.memo:
             raise TypeError("cannot marshal recursive dictionaries")
         self.memo[i] = None
         dump = self.__dump
         write("<value><struct>\n")
-        for k, v in value.items():
+        for k, v in list(value.items()):
             write("<member>\n")
             if type(k) is not StringType:
-                if unicode and type(k) is UnicodeType:
+                if str and type(k) is UnicodeType:
                     k = k.encode(self.encoding)
                 else:
                     raise TypeError("dictionary key must be string")
@@ -1230,12 +1227,12 @@ class Transport:
         if isinstance(host, TupleType):
             host, x509 = host
 
-        import urllib
-        auth, host = urllib.splituser(host)
+        import urllib.request, urllib.parse, urllib.error
+        auth, host = urllib.parse.splituser(host)
 
         if auth:
             import base64
-            auth = base64.encodestring(urllib.unquote(auth))
+            auth = base64.encodestring(urllib.parse.unquote(auth))
             auth = string.join(string.split(auth), "") # get rid of whitespace
             extra_headers = [
                 ("Authorization", "Basic " + auth)
@@ -1253,9 +1250,9 @@ class Transport:
 
     def make_connection(self, host):
         # create a HTTP connection object from a host descriptor
-        import httplib
+        import http.client
         host, extra_headers, x509 = self.get_host_info(host)
-        return httplib.HTTP(host)
+        return http.client.HTTP(host)
 
     ##
     # Send request header.
@@ -1278,7 +1275,7 @@ class Transport:
         connection.putheader("Host", host)
         if extra_headers:
             if isinstance(extra_headers, DictType):
-                extra_headers = extra_headers.items()
+                extra_headers = list(extra_headers.items())
             for key, value in extra_headers:
                 connection.putheader(key, value)
 
@@ -1355,10 +1352,10 @@ class SafeTransport(Transport):
     def make_connection(self, host):
         # create a HTTPS connection object from a host descriptor
         # host may be a string, or a (host, x509-dict) tuple
-        import httplib
+        import http.client
         host, extra_headers, x509 = self.get_host_info(host)
         try:
-            HTTPS = httplib.HTTPS
+            HTTPS = http.client.HTTPS
         except AttributeError:
             raise NotImplementedError(
                 "your version of httplib doesn't support HTTPS"
@@ -1410,11 +1407,11 @@ class ServerProxy:
         # establish a "logical" server connection
 
         # get the url
-        import urllib
-        type, uri = urllib.splittype(uri)
+        import urllib.request, urllib.parse, urllib.error
+        type, uri = urllib.parse.splittype(uri)
         if type not in ("http", "https"):
             raise IOError("unsupported XML-RPC protocol")
-        self.__host, self.__handler = urllib.splithost(uri)
+        self.__host, self.__handler = urllib.parse.splithost(uri)
         if not self.__handler:
             self.__handler = "/RPC2"
 
