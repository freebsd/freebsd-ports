--- phabricator/__init__.py.orig	2013-11-26 21:00:52 UTC
+++ phabricator/__init__.py
@@ -288,15 +288,19 @@ class Phabricator(Resource):
     }
 
     def __init__(self, username=None, certificate=None, host=None,
-            timeout=5, response_format='json', **kwargs):
+            timeout=5, response_format='json', token=None, **kwargs):
 
         # Set values in ~/.arcrc as defaults
         if ARCRC:
             self.host = host if host else ARCRC['hosts'].keys()[0]
-            self.username = username if username else ARCRC['hosts'][self.host]['user']
-            self.certificate = certificate if certificate else ARCRC['hosts'][self.host]['cert']
+            if token or ARCRC['hosts'][self.host].has_key('token'):
+                self.token = token if token else ARCRC['hosts'][self.host]['token']
+            else:
+                self.username = username if username else ARCRC['hosts'][self.host]['user']
+                self.certificate = certificate if certificate else ARCRC['hosts'][self.host]['cert']
         else:
             self.host = host
+            self.token = token
             self.username = username
             self.certificate = certificate
 
@@ -313,6 +317,12 @@ class Phabricator(Resource):
         raise SyntaxError('You cannot call the Conduit API without a resource.')
 
     def connect(self):
+        if self.token:
+            self.conduit = {
+                'token': self.token
+            }
+            return
+
         auth = Resource(api=self, method='conduit', endpoint='connect')
 
         response = auth(user=self.username, host=self.host,
