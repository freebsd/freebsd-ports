--- mix.exs.orig	2015-08-18 15:22:09 UTC
+++ mix.exs
@@ -14,11 +14,7 @@ defmodule ReleaseManager.Mixfile do
   def application, do: []
 
   def deps do
-    [{:conform, "~> 0.16.0"},
-     {:relx, "~> 3.1.0" },
-     {:earmark, "~> 0.1", only: :dev},
-     {:ex_doc, "~> 0.5", only: :dev},
-     {:coverex, "~> 1.4.1", only: :test}]
+    []
   end
 
   defp description do
