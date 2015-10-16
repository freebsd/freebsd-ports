--- mix.exs.orig	2015-09-24 19:41:49 UTC
+++ mix.exs
@@ -8,7 +8,7 @@ defmodule Tzdata.Mixfile do
      elixir: "~> 1.0 or ~> 1.1",
      package: package,
      description: description,
-     deps: deps]
+     deps: []]
   end
 
   def application do
