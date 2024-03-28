--- test/cli.fnl.orig	2024-03-28 21:47:12 UTC
+++ test/cli.fnl
@@ -14,7 +14,7 @@
                   (p:read :*all)
                   (if (p:close)
                       long
-                      "lua")))
+                      (or (os.getenv "LUA") "lua"))))
 
 (fn file-exists? [filename]
   (let [f (io.open filename)]
