--- mix.exs.orig	2015-06-30 19:58:41 UTC
+++ mix.exs
@@ -13,10 +13,7 @@ defmodule ReleaseManager.Mixfile do
   def application, do: []
 
   def deps do
-    [{:conform, "~> 0.14.5"},
-     {:relx, "~> 3.1.0" },
-     {:earmark, "~> 0.1", only: :dev},
-     {:ex_doc, "~> 0.5", only: :dev}]
+    []
   end
 
   defp description do
