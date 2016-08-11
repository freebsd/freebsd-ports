--- lib/execjs/runtimes.rb.orig 2016-04-25 16:51:44 UTC
+++ lib/execjs/runtimes.rb
@@ -17,7 +17,7 @@ module ExecJS
 
     Node = ExternalRuntime.new(
       name:        "Node.js (V8)",
-      command:     ["nodejs", "node"],
+      command:     ["nodejs", "node", "%%LOCALBASE%%/bin/node"],
       runner_path: ExecJS.root + "/support/node_runner.js",
       encoding:    'UTF-8'
     )
