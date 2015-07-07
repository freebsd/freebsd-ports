--- mix.exs.orig	2015-07-03 15:18:59 UTC
+++ mix.exs
@@ -29,10 +29,7 @@ defmodule TimexEcto.Mixfile do
   #
   # Type `mix help deps` for more examples and options
   defp deps do
-    [{:timex, "~> 0.16.0"},
-     {:ecto, "~> 0.12.1"},
-     {:earmark, "~> 0.1", only: :dev},
-     {:ex_doc, "~> 0.5", only: :dev}]
+    []
   end
 
   defp package do
