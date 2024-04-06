From: Escape0707 <tothesong@gmail.com>
Date: Fri, 5 Apr 2024 21:12:06 +0900
Subject: [PATCH] Ignore exception raised by pip_system_certs not found (#3114)

This dependency usually doesn't benefit Linux distros with requests library
configured to use system certificate already. And is not packaged by most
distros. Making it optional will make most Linux users' installation much
easier.

Obtained from:

https://github.com/ankitects/anki/commit/97efd49cd8db15a84d2ae2701d21b8283e37bc8c

--- qt/aqt/__init__.py.orig	2024-03-31 06:57:06 UTC
+++ qt/aqt/__init__.py
@@ -6,7 +6,12 @@ import sys
 import logging
 import sys
 
-import pip_system_certs.wrapt_requests
+try:
+    import pip_system_certs.wrapt_requests
+except ModuleNotFoundError:
+    print(
+        "Python module pip_system_certs is not installed. System certificate store and custom SSL certificates may not work. See: https://github.com/ankitects/anki/issues/3016"
+    )
 
 if sys.version_info[0] < 3 or sys.version_info[1] < 9:
     raise Exception("Anki requires Python 3.9+")
