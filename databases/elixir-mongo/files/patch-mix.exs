--- mix.exs.orig	2015-09-18 11:03:06 UTC
+++ mix.exs
@@ -5,10 +5,9 @@ defmodule Mongo.Mixfile do
     [ app: :mongo,
       name: "mongo",
       version: "0.5.1",
-      elixir: "~> 1.0.0",
+      elixir: ">= 1.0.0",
       source_url: "https://github.com/checkiz/elixir-mongo",
       description: "MongoDB driver for Elixir",
-      deps: deps(Mix.env),
       package: package,
       docs: &docs/0 ]
   end
