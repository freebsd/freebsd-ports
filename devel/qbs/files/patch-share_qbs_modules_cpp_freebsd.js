freebsd: fix support for STABLE and CURRENT releases

https://code.qt.io/cgit/qbs/qbs.git/commit/?h=3.0&id=a0dfa99c6071fede3be6522102818839a7f8365a

--- share/qbs/modules/cpp/freebsd.js.orig	2025-06-20 12:42:25 UTC
+++ share/qbs/modules/cpp/freebsd.js
@@ -1,8 +1,13 @@ function stripKernelReleaseSuffix(r) {
 var Utilities = require("qbs.Utilities");
 
 function stripKernelReleaseSuffix(r) {
-    var idx = r.indexOf("-RELEASE");
-    return idx >= 0 ? r.substr(0, idx) : r;
+    var suffixes = ["-RELEASE", "-STABLE", "-CURRENT"];
+    for (var i = 0; i < suffixes.length; i++) {
+        var idx = r.indexOf(suffixes[i]);
+        if (idx >= 0)
+            return r.substr(0, idx);
+    }
+    return r;
 }
 
 function hostKernelRelease() {
