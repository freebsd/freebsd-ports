--- project.janet.orig	2025-09-05 00:00:02 UTC
+++ project.janet
@@ -7,16 +7,17 @@
                  "https://github.com/ianthehenry/judge.git"
                  "https://github.com/CFiggers/cmd.git"])
 
-# (def cflags
-#   (case (os/which)
-#     :windows []
-#     ["-s"]))
+(def cflags
+  (case (os/which)
+    :windows []
+    :freebsd []
+    ["-s"]))
 
-# (declare-executable
-#   :name "janet-lsp"
-#   :entry "src/main.janet"
-#   :cflags cflags
-#   :install true)
+(declare-executable
+  :name "janet-lsp"
+  :entry "src/main.janet"
+  :cflags cflags
+  :install true)
 
 (declare-archive
   :name "janet-lsp"
