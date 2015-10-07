--- mix.exs.orig	2015-08-18 14:59:08 UTC
+++ mix.exs
@@ -26,9 +26,6 @@ defmodule Conform.Mixfile do
   defp compilers(_),    do: nil
 
   defp deps(true), do: [
-    {:neotoma, "~> 1.7.3"},
-    {:ex_doc, "~> 0.7", only: [:docs, :dev]},
-    {:earmark, "~> 0.1", only: [:docs, :dev]}
   ]
   defp deps(_),    do: []
 
