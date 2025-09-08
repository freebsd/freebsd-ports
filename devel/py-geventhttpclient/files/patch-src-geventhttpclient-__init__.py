--- src/geventhttpclient/__init__.py.orig	2025-08-24 09:56:07 UTC
+++ src/geventhttpclient/__init__.py
@@ -1,6 +1,6 @@
 # package
 
-__version__ = "2.3.4"  # don't forget to update version in pyproject.toml as well
+__version__ = "%%PORTVERSION%%"  # don't forget to update version in pyproject.toml as well
 
 from geventhttpclient.api import delete, get, head, options, patch, post, put, request
 from geventhttpclient.client import HTTPClient
