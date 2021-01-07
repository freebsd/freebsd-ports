--- mix.exs.orig	2020-12-21 15:11:39 UTC
+++ mix.exs
@@ -9,7 +9,6 @@ defmodule ExCoveralls.Mixfile do
       version: "0.13.4",
       elixir: "~> 1.3",
       elixirc_paths: elixirc_paths(Mix.env()),
-      deps: deps(),
       docs: docs(),
       description: description(),
       package: package(),
