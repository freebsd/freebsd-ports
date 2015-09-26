--- mix.exs.orig	2015-09-26 08:10:10 UTC
+++ mix.exs
@@ -5,7 +5,6 @@ defmodule Bson.Mixfile do
     [ app: :bson,
       name: "bson",
       version: "0.4.3",
-      elixir: "~> 1.0.0",
       description: "BSON implementation for Elixir",
       source_url: "https://github.com/checkiz/elixir-bson",
       deps: deps(Mix.env),
