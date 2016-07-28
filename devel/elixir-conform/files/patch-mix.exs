--- mix.exs.orig	2016-07-28 11:30:56 UTC
+++ mix.exs
@@ -26,8 +26,7 @@ defmodule Conform.Mixfile do
   defp compilers(_),    do: nil
 
   defp deps do
-    [{:neotoma, "~> 1.7.3"},
-     {:ex_doc, "~> 0.13", only: :dev}]
+    []
   end
 
   defp description, do: "Easy release configuration for Elixir apps."
