--- mix.exs.orig	2015-10-17 21:00:59 UTC
+++ mix.exs
@@ -5,8 +5,7 @@ defmodule CSV.Mixfile do
     [
         app: :csv,
         version: "1.2.1",
-        elixir: "~> 1.1.0",
-        deps: deps,
+        elixir: "~> 1.0",
         package: package,
         docs: &docs/0,
         name: "CSV",
