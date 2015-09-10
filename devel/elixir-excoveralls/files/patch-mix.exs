--- mix.exs.orig	2015-07-29 09:42:45 UTC
+++ mix.exs
@@ -5,7 +5,6 @@ defmodule ExCoveralls.Mixfile do
     [ app: :excoveralls,
       version: "0.3.11",
       elixir: "~> 1.0",
-      deps: deps,
       description: description,
       package: package,
       test_coverage: [tool: ExCoveralls]
