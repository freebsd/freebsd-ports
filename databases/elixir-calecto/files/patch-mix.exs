--- mix.exs.orig	2016-07-07 13:38:54 UTC
+++ mix.exs
@@ -16,11 +16,6 @@ defmodule Calecto.Mixfile do
 
   defp deps do
     [
-      {:ecto, "~> 1.1.3 or ~> 2.0.0 or ~> 2.0.0-rc5"},
-      {:calendar, "~> 0.16.0"},
-
-      {:earmark, "~> 0.2.1", only: :dev},
-      {:ex_doc, "~> 0.11.3", only: :dev},
     ]
   end
 
