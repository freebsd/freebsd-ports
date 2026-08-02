--- scripts/build.py.orig	2025-12-16 02:55:22 UTC
+++ scripts/build.py
@@ -53,6 +53,12 @@ def download_libcurl():
 
 
 def download_libcurl():
+    # On FreeBSD, use system-installed curl-impersonate
+    if arch["system"] == "FreeBSD":
+        print("Using system curl-impersonate on FreeBSD")
+        arch["libdir"] = "/usr/local/lib"
+        return
+
     if (Path(arch["libdir"]) / arch["so_name"]).exists():
         print(".so files already downloaded.")
         return
@@ -132,7 +138,7 @@ def get_curl_libraries():
         ]
     elif arch["system"] == "Darwin" or (
         arch["system"] == "Linux" and arch.get("link_type") == "dynamic"
-    ):
+    ) or arch["system"] == "FreeBSD":
         return ["curl-impersonate"]
     else:
         return []
