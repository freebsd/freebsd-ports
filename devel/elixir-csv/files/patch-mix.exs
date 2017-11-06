--- mix.exs.orig	2017-05-29 18:05:18 UTC
+++ mix.exs
@@ -6,7 +6,6 @@ defmodule CSV.Mixfile do
         app: :csv,
         version: "2.0.0",
         elixir: "~> 1.1",
-        deps: deps(),
         package: package(),
         docs: &docs/0,
         name: "CSV",
