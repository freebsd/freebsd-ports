--- odoo/http.py.orig	2025-07-19 21:02:41 UTC
+++ odoo/http.py
@@ -257,13 +257,12 @@ ROUTING_KEYS = {
     'alias', 'host', 'methods',
 }
 
-if parse_version(werkzeug.__version__) >= parse_version('2.0.2'):
-    # Werkzeug 2.0.2 adds the websocket option. If a websocket request
-    # (ws/wss) is trying to access an HTTP route, a WebsocketMismatch
-    # exception is raised. On the other hand, Werkzeug 0.16 does not
-    # support the websocket routing key. In order to bypass this issue,
-    # let's add the websocket key only when appropriate.
-    ROUTING_KEYS.add('websocket')
+# Werkzeug 2.0.2 adds the websocket option. If a websocket request
+# (ws/wss) is trying to access an HTTP route, a WebsocketMismatch
+# exception is raised. On the other hand, Werkzeug 0.16 does not
+# support the websocket routing key. In order to bypass this issue,
+# let's add the websocket key only when appropriate.
+ROUTING_KEYS.add('websocket')
 
 # The default duration of a user session cookie. Inactive sessions are reaped
 # server-side as well with a threshold that can be set via an optional
