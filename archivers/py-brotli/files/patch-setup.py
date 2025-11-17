--- setup.py.orig	2025-11-05 18:03:58 UTC
+++ setup.py
@@ -142,7 +142,7 @@ NAME = "brotli"
 
 NAME = "brotli"
 
-VERSION = get_version()
+VERSION = "%%PORTVERSION%%"
 
 URL = "https://github.com/google/brotli"
 
