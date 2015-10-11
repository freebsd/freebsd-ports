--- mix.exs.orig	2015-10-10 09:51:10 UTC
+++ mix.exs
@@ -7,7 +7,6 @@ defmodule ReleaseManager.Mixfile do
       elixir: "~> 1.0",
       description: description,
       package: package,
-      deps: deps,
       docs: docs,
       test_coverage: [tool: Coverex.Task, coveralls: true]]
   end
