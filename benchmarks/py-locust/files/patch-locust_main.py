--- locust/main.py.orig	2025-06-12 22:34:12 UTC
+++ locust/main.py
@@ -454,7 +454,7 @@ See https://github.com/locustio/locust/wiki/Installati
             sys.exit(1)
         if options.web_host == "*":
             # special check for "*" so that we're consistent with --master-bind-host
-            web_host = ""
+            web_host = "0.0.0.0"
         else:
             web_host = options.web_host
         if web_host:
