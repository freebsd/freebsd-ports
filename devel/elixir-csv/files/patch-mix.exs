--- mix.exs.orig	2015-07-11 17:38:59 UTC
+++ mix.exs
@@ -6,7 +6,6 @@ defmodule CSV.Mixfile do
         app: :csv,
         version: "1.0.1",
         elixir: "~> 1.0.0 or ~> 1.1-dev",
-        deps: deps,
         package: package,
         docs: &docs/0,
         name: "CSV",
