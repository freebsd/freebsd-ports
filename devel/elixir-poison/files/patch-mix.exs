--- mix.exs.orig	2015-06-30 13:45:21 UTC
+++ mix.exs
@@ -29,11 +29,7 @@ defmodule Poison.Mixfile do
   #
   # Type `mix help deps` for more examples and options
   defp deps do
-    [{:earmark, "~> 0.1", only: :docs},
-     {:ex_doc, "~> 0.7", only: :docs},
-     {:jiffy, github: "davisp/jiffy", only: :bench},
-     {:exjsx, github: "talentdeficit/exjsx", only: :bench},
-     {:jazz, github: "meh/jazz", only: :bench}]
+    []
   end
 
   defp package do
