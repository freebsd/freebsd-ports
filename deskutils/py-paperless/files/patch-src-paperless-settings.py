--- src/paperless/settings.py.orig	2019-01-27 13:48:05 UTC
+++ src/paperless/settings.py
@@ -104,7 +104,7 @@ MIDDLEWARE = [
 ]
 
 # We allow CORS from localhost:8080
-CORS_ORIGIN_WHITELIST = tuple(os.getenv("PAPERLESS_CORS_ALLOWED_HOSTS", "localhost:8080").split(","))
+CORS_ORIGIN_WHITELIST = tuple(os.getenv("PAPERLESS_CORS_ALLOWED_HOSTS", "http://localhost:8080").split(","))
 
 # If auth is disabled, we just use our "bypass" authentication middleware
 if bool(os.getenv("PAPERLESS_DISABLE_LOGIN", "false").lower() in ("yes", "y", "1", "t", "true")):
