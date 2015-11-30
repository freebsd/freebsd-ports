--- mix.exs.orig	2015-11-30 21:02:08 UTC
+++ mix.exs
@@ -25,13 +25,10 @@ defmodule Conform.Mixfile do
   defp compilers(true), do: [:peg, :erlang, :elixir, :app]
   defp compilers(_),    do: nil
 
-  defp deps(true), do: [{:neotoma, "~> 1.7.3"}] ++ core_deps()
+  defp deps(true), do: [] ++ core_deps()
   defp deps(_),    do: core_deps()
 
   defp core_deps(), do: [
-    {:exrm, "~> 1.0.0-rc5", optional: true},
-    {:ex_doc, "~> 0.7", only: [:docs, :dev]},
-    {:earmark, "~> 0.1", only: [:docs, :dev]}
   ]
 
   defp description, do: "Easy release configuration for Elixir apps."
