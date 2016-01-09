--- mix.exs.orig	2016-01-01 13:36:17 UTC
+++ mix.exs
@@ -4,7 +4,7 @@ defmodule Dialyze.Mixfile do
   def project do
     [app: :dialyze,
      version: "0.1.4-min_plt",
-     elixir: "~> 0.14.3 or ~> 0.15.0 or ~> 1.0.0 or ~> 1.1.0-dev",
+     elixir: "~> 0.14.3 or ~> 0.15.0 or ~> 1.0",
      description: "Dialyzer mix task",
      deps: [],
      aliases: [install: ["compile", "archive.build", "archive.install --force"]],
