--- go/private/sdk.bzl.orig	2026-02-09 09:46:54.000000000 +0900
+++ go/private/sdk.bzl	2026-04-27 12:31:50.253943000 +0900
@@ -575,17 +575,17 @@
     }
 
 def fetch_sdks_by_version(ctx, allow_fail = False):
-    result = ctx.download(
-        url = [
-            "https://go.dev/dl/?mode=json&include=all",
-            "https://golang.google.cn/dl/?mode=json&include=all",
-        ],
-        output = "versions.json",
-        allow_fail = allow_fail,
-    )
-    if not result.success:
-        return None
-    data = ctx.read("versions.json")
+    #result = ctx.download(
+    #    url = [
+    #        "https://go.dev/dl/?mode=json&include=all",
+    #        "https://golang.google.cn/dl/?mode=json&include=all",
+    #    ],
+    #    output = "versions.json",
+    #    allow_fail = allow_fail,
+    #)
+    #if not result.success:
+    #    return None
+    data = ctx.read("%%BAZEL_WRKSRC%%/versions.json")
 
     # If the download is redirected through a proxy such as Artifactory, it may
     # drop the query parameters and return an HTML page instead. In that case,
@@ -596,7 +596,7 @@
 
     # module_ctx doesn't have delete, but its files are temporary anyway.
     if hasattr(ctx, "delete"):
-        ctx.delete("versions.json")
+        ctx.delete("%%BAZEL_WRKSRC%%/versions.json")
     return _parse_versions_json(data)
 
 def parse_version(version):
