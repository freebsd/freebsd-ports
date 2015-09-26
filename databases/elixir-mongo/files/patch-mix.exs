--- mix.exs.orig	2015-04-23 23:09:40 UTC
+++ mix.exs
@@ -5,7 +5,6 @@ defmodule Mongo.Mixfile do
     [ app: :mongo,
       name: "mongo",
       version: "0.5.1",
-      elixir: "~> 1.0.0",
       source_url: "https://github.com/checkiz/elixir-mongo",
       description: "MongoDB driver for Elixir",
       deps: deps(Mix.env),
@@ -24,7 +23,6 @@ defmodule Mongo.Mixfile do
   # Returns the list of dependencies for prod
   defp deps(:prod) do
     [
-      bson: "~> 0.4.3"
     ]
   end
 
