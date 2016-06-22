--- mix.exs.orig	2016-06-22 07:43:11 UTC
+++ mix.exs
@@ -5,7 +5,6 @@ defmodule ExCoveralls.Mixfile do
     [ app: :excoveralls,
       version: "0.5.5",
       elixir: "~> 1.0",
-      deps: deps(),
       description: description(),
       package: package(),
       test_coverage: [tool: ExCoveralls],
