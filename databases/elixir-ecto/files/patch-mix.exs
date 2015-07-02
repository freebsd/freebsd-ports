--- mix.exs.orig	2015-07-02 10:32:17 UTC
+++ mix.exs
@@ -33,14 +33,7 @@ defmodule Ecto.Mixfile do
   end
 
   defp deps do
-    [{:poolboy, "~> 1.4"},
-     {:decimal, "~> 1.0"},
-     {:postgrex, "~> 0.8.3", optional: true},
-     {:mariaex, "~> 0.3.0", optional: true},
-     {:poison, "~> 1.0", optional: true},
-     {:ex_doc, "~> 0.7", only: :docs},
-     {:earmark, "~> 0.1", only: :docs},
-     {:inch_ex, only: :docs}]
+    []
   end
 
   defp test_paths(adapter) when adapter in @adapters, do: ["integration_test/#{adapter}"]
