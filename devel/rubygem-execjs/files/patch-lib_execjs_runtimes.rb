--- lib/execjs/runtimes.rb.orig	2021-06-28 15:24:59 UTC
+++ lib/execjs/runtimes.rb
@@ -17,7 +17,7 @@ module ExecJS
 
     Node = ExternalRuntime.new(
       name:        "Node.js (V8)",
-      command:     ["node", "nodejs"],
+      command:     ["%%LOCALBASE%%/bin/node", "node", "nodejs"],
       runner_path: ExecJS.root + "/support/node_runner.js",
       encoding:    'UTF-8'
     )
