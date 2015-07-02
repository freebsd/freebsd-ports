--- mix.exs.orig	2015-06-29 10:03:33 UTC
+++ mix.exs
@@ -25,7 +25,6 @@ defmodule Conform.Mixfile do
   defp compilers(true), do: [:peg, :erlang, :elixir, :app]
   defp compilers(_),    do: nil
 
-  defp deps(true), do: [{:neotoma, github: "seancribbs/neotoma"}]
   defp deps(_),    do: []
 
   defp description, do: "Easy release configuration for Elixir apps."
