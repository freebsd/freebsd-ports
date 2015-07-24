--- mix.exs.orig	2015-07-19 17:59:14 UTC
+++ mix.exs
@@ -9,7 +9,7 @@ defmodule Ecto.Mixfile do
     [app: :ecto,
      version: @version,
      elixir: "~> 1.0",
-     deps: deps,
+     deps: [],
      build_per_environment: false,
      test_paths: test_paths(Mix.env),
 
