--- odoo/http.py	2020-04-21 16:59:04.084246000 -0500
+++ odoo/http.py	2020-04-21 17:04:53.110315000 -0500
@@ -26,13 +26,14 @@
 
 import babel.core
 from datetime import datetime, date
+import secure_cookie.session
 import passlib.utils
 import psycopg2
 import json
-import werkzeug.contrib.sessions
 import werkzeug.datastructures
 import werkzeug.exceptions
 import werkzeug.local
+import werkzeug.middleware.shared_data
 import werkzeug.routing
 import werkzeug.wrappers
 import werkzeug.wsgi
@@ -966,7 +967,7 @@
 class SessionExpiredException(Exception):
     pass
 
-class OpenERPSession(werkzeug.contrib.sessions.Session):
+class OpenERPSession(secure_cookie.session.Session):
     def __init__(self, *args, **kwargs):
         self.inited = False
         self.modified = False
@@ -1267,7 +1268,7 @@
         # Setup http sessions
         path = odoo.tools.config.session_dir
         _logger.debug('HTTP sessions stored in: %s', path)
-        return werkzeug.contrib.sessions.FilesystemSessionStore(
+        return secure_cookie.session.FilesystemSessionStore(
             path, session_class=OpenERPSession, renew_missing=True)
 
     @lazy_property
@@ -1310,7 +1311,7 @@
 
         if statics:
             _logger.info("HTTP Configuring static files")
-        app = werkzeug.wsgi.SharedDataMiddleware(self.dispatch, statics, cache_timeout=STATIC_CACHE)
+        app = werkzeug.middleware.shared_data.SharedDataMiddleware(self.dispatch, statics, cache_timeout=STATIC_CACHE)
         self.dispatch = DisableCacheMiddleware(app)
 
     def setup_session(self, httprequest):
