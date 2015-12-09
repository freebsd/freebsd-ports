--- mix.exs.orig	2015-12-01 21:16:44 UTC
+++ mix.exs
@@ -8,7 +8,6 @@ defmodule Mongo.Mixfile do
       elixir: "~> 1.0 or ~> 1.1",
       source_url: "https://github.com/checkiz/elixir-mongo",
       description: "MongoDB driver for Elixir",
-      deps: deps(Mix.env),
       package: package,
       docs: &docs/0 ]
   end
