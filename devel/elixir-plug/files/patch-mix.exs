--- mix.exs.orig	2015-07-01 09:49:57 UTC
+++ mix.exs
@@ -24,11 +24,7 @@ defmodule Plug.Mixfile do
   end
 
   def deps do
-    [{:cowboy, "~> 1.0", optional: true},
-     {:earmark, "~> 0.1", only: :docs},
-     {:ex_doc, "~> 0.7", only: :docs},
-     {:inch_ex, only: :docs},
-     {:hackney, "~> 0.13", only: :test}]
+    []
   end
 
   defp package do
