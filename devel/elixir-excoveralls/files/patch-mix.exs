--- mix.exs.orig	2017-01-06 11:20:27 UTC
+++ mix.exs
@@ -5,7 +5,6 @@ defmodule ExCoveralls.Mixfile do
     [ app: :excoveralls,
       version: "0.6.0",
       elixir: "~> 1.2",
-      deps: deps(),
       description: description(),
       package: package(),
       test_coverage: [tool: ExCoveralls],
