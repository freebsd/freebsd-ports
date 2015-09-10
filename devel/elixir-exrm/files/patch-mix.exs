--- mix.exs.orig	2015-09-06 10:06:04 UTC
+++ mix.exs
@@ -7,7 +7,7 @@ defmodule ReleaseManager.Mixfile do
       elixir: "~> 1.0.5",
       description: description,
       package: package,
-      deps: deps,
+      deps: [],
       test_coverage: [tool: Coverex.Task, coveralls: true]]
   end
 
