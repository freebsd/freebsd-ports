--- mix.exs.orig	2015-07-02 10:57:08 UTC
+++ mix.exs
@@ -23,9 +23,7 @@ defmodule Postgrex.Mixfile do
   end
 
   defp deps do
-    [{:ex_doc, only: :dev},
-     {:earmark, only: :dev},
-     {:decimal, "~> 1.0"}]
+    []
   end
 
   defp description do
