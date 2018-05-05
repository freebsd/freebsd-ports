--- mix.exs.orig	2018-05-03 07:42:57 UTC
+++ mix.exs
@@ -6,7 +6,6 @@ defmodule ExCoveralls.Mixfile do
       version: "0.8.2",
       elixir: "~> 1.2",
       elixirc_paths: elixirc_paths(Mix.env()),
-      deps: deps(),
       description: description(),
       package: package(),
       test_coverage: [tool: ExCoveralls],
