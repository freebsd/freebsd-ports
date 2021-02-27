--- mix.exs.orig	2015-09-18 11:00:09 UTC
+++ mix.exs
@@ -5,11 +5,10 @@ defmodule Bson.Mixfile do
     [ app: :bson,
       name: "bson",
       version: "0.4.3",
-      elixir: "~> 1.0.0",
       description: "BSON implementation for Elixir",
       source_url: "https://github.com/checkiz/elixir-bson",
       deps: deps(Mix.env),
-      package: package,
+      package: package(),
       docs: &docs/0 ]
   end
 
